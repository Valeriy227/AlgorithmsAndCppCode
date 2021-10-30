//#pragma once

#include <initializer_list>
#include <algorithm>

constexpr int kBlockSize = 512 / sizeof(int);

class Batch {
public:
  Batch() {
    block = new int[kBlockSize];
  }
  ~Batch() {
    delete[] block;
  }
  void PushRight(int value) {
    block[end] = value;
    end++;
  }
  void PushLeft(int value) {
    begin--;
    block[begin] = value;
  }

  Batch* Copy() {
    Batch* batch = new Batch;
    batch->begin = begin;
    batch->end = end;
    for (int i = 0; i < kBlockSize; ++i) {
      batch->block[i] = block[i];
    }
    return batch;
  }

public:
  int* block;
  int begin = -1, end = -1;
};

class Deque {
public:
  Deque() {
    cnt_of_batches_ = 1;
    batches_ = new Batch*[cnt_of_batches_];

    batches_[0] = new Batch;
    batches_[0]->begin = 0;
    batches_[0]->end = 0;

    size_ = 0;
    head_ = 0;
    tail_ = 0;
  }
  Deque(const Deque& rhs) {
    size_ = rhs.size_;
    head_ = rhs.head_;
    tail_ = rhs.tail_;
    cnt_of_batches_ = rhs.cnt_of_batches_;

    batches_ = new Batch*[cnt_of_batches_];
    for (size_t i = 0; i < cnt_of_batches_; ++i) {
      batches_[i] = rhs.batches_[i]->Copy();
    }
  }
  Deque(Deque&& rhs) : Deque() {
    Swap(rhs);
  }
  explicit Deque(size_t size) : Deque() {
    for (size_t i = 0; i < size; ++i) {
      PushBack(0);
    }
  }

  Deque(std::initializer_list<int> list) : Deque() {
    for (auto i : list) {
      PushBack(i);
    }
  }

  ~Deque() {
    for (size_t i = 0; i < cnt_of_batches_; ++i) {
      delete batches_[i];
    }
    delete[] batches_;
  }

  Deque& operator=(const Deque& rhs) {
    if (this != &rhs) {
      for (size_t i = 0; i < cnt_of_batches_; ++i) {
        delete batches_[i];
      }
      delete[] batches_;

      size_ = rhs.size_;
      head_ = rhs.head_;
      tail_ = rhs.tail_;
      cnt_of_batches_ = rhs.cnt_of_batches_;

      batches_ = new Batch*[cnt_of_batches_];
      for (size_t i = 0; i < cnt_of_batches_; ++i) {
        batches_[i] = rhs.batches_[i]->Copy();
      }
    }
    return *this;
  }
  Deque& operator=(Deque&& rhs) {
    if (this != &rhs) {
      Swap(rhs);
    }
    return *this;
  }

  void Swap(Deque& rhs) {
    std::swap(batches_, rhs.batches_);
    std::swap(size_, rhs.size_);
    std::swap(head_, rhs.head_);
    std::swap(tail_, rhs.tail_);
    std::swap(cnt_of_batches_, rhs.cnt_of_batches_);
  }

  void PushBack(int value) {
    batches_[tail_]->PushRight(value);

    if (batches_[tail_]->end == kBlockSize) {
      CheckCapacity();

      auto new_tail = IndNext(tail_);
      batches_[new_tail]->begin = 0;
      batches_[new_tail]->end = 0;
      tail_ = new_tail;
    }
    size_++;
  }

  void PopBack() {
    if (batches_[tail_]->end == 0) {
      batches_[tail_]->begin = -1;
      batches_[tail_]->end = -1;
      tail_ = IndPrev(tail_);
    }
    batches_[tail_]->end--;
    size_--;
  }

  void PushFront(int value) {
    if (batches_[head_]->begin == 0) {
      CheckCapacity();

      auto new_head = IndPrev(head_);
      batches_[new_head]->begin = kBlockSize;
      batches_[new_head]->end = kBlockSize;
      head_ = new_head;
    }
    batches_[head_]->PushLeft(value);
    size_++;
  }

  void PopFront() {
    batches_[head_]->begin++;
    if (batches_[head_]->begin == kBlockSize) {
      batches_[head_]->begin = -1;
      batches_[head_]->end = -1;
      tail_ = IndPrev(tail_);
    }
    size_--;
  }

  int& operator[](size_t ind) {
    auto tmp = GetLocation(ind);
    auto ind_block = tmp.first, ind_element = tmp.second;
//        auto [ind_block, ind_element] = GetLocation(ind);
    return batches_[ind_block]->block[ind_element];
  }

  int operator[](size_t ind) const {
    auto tmp = GetLocation(ind);
    auto ind_block = tmp.first, ind_element = tmp.second;
//        auto [ind_block, ind_element] = GetLocation(ind);
    return batches_[ind_block]->block[ind_element];
  }

  size_t Size() const {
    return size_;
  }

  void Clear() {
    while (size_ > 0) {
      PopBack();
    }
  }

private:
  void CheckCapacity() {
//    if (IndNext(tail_) == head_) {
    if (IndNext(tail_) == 0 || IndPrev(head_) == cnt_of_batches_ - 1) {
      auto new_batches = new Batch*[cnt_of_batches_ * 2];
//      for (size_t i = 0, cur = head_; i < cnt_of_batches_; ++i, cur = IndNext(cur)) {
      for (size_t i = 0, cur = head_; i < cnt_of_batches_; ++i, cur = IndNext(cur)) {
        std::swap(new_batches[i + cnt_of_batches_ / 2], batches_[cur]);
      }
      for (size_t i = cnt_of_batches_; i < cnt_of_batches_ * 2; ++i) {
        new_batches[i] = new Batch;
      }
      std::swap(batches_, new_batches);

      head_ = cnt_of_batches_ / 2;
      tail_ = cnt_of_batches_ - 1;
      cnt_of_batches_ *= 2;
    }
  }

  size_t IndNext(size_t ind) {
    if (ind == cnt_of_batches_ - 1) {
      return 0;
    }
    return ind + 1;
  }
  size_t IndPrev(size_t ind) {
    if (ind == 0) {
      return cnt_of_batches_ - 1;
    }
    return ind - 1;
  }

  std::pair<int, int> GetLocation(size_t ind) const {
//    int cnt_in_head = batches_[head_]->end - batches_[head_]->begin;
//    if (cnt_in_head > static_cast<int>(ind)) {
//      int ind_element = batches_[head_]->begin + ind;
//      return {head_, ind_element};
//    } else {
//      ind -= cnt_in_head;
//      auto ind_block = (head_ + 1 + ind / kBlockSize) % cnt_of_batches_;
//      auto ind_element = ind % kBlockSize;
//      return {ind_block, ind_element};
//    }
    int ind_block = head_;
    int ind_element = batches_[head_]->begin;
    for (int i = 0; i < )
  }

public:
  Batch** batches_;
  size_t size_;
  size_t head_;
  size_t tail_;
  size_t cnt_of_batches_ = 0;
};
