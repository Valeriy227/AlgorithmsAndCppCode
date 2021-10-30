//#include <catch.hpp>

#include <cassert>
#include <deque>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "deque.h"
using namespace std;

template <typename T>
bool REQUIRE(T a, T b) {
  if (a != b) {
    std::cout << a << " " << b << endl;
    return false;
  }
  return true;
}

//void Check(const Deque& actual, const std::vector<int>& expected) {
//    REQUIRE(actual.Size() == expected.size());
//    for (size_t i = 0; i < actual.Size(); ++i) {
//        REQUIRE(actual[i] == expected[i]);
//    }
//}

void Check(const Deque& actual, const std::vector<int>& expected) {
  REQUIRE(actual.Size(), expected.size());
//  for (int i = 0; i < actual.Size(); ++i) {
//    std::cout << actual[i] << " ";
//  }
//  cout << endl;
  for (size_t i = 0; i < actual.Size(); ++i) {
    REQUIRE(actual[i], expected[i]);
  }
}


int main() {
  const int iterations = 1e4;
  Deque a;
  std::deque<int> b;
  std::mt19937 gen(735675);
  std::uniform_int_distribution<int> dist(1, 5);

  for (int i = 0; i < iterations; ++i) {
    a.PushFront(i);
    b.push_front(i);
  }

  for (int i = 0; i < iterations; ++i) {
    if (i == 521) {
      cout << "stop" << endl;
    }
    int code = dist(gen);
    int value = gen();
    if (code == 1) {
      a.PushFront(value);
      b.push_front(value);
    } else if (code == 2) {
      a.PushBack(value);
      b.push_back(value);
      cout << a[a.Size() - 1] << " " << b[b.size() - 1] << endl;
    } else if (code == 3) {
      a.PopFront();
      b.pop_front();
    } else if (code == 4) {
//      if (a.Size() >= 9967) {
//        cout << "stop" << endl;
//      }
      a.PopBack();
      b.pop_back();
    } else {
      int index = static_cast<int>(value % a.Size());
      if (!REQUIRE(a[index], b[index])) {
        cout << "!!!!" << endl;
      }
    }
    cout << a.Size() << " " << a.head_ << " " << a.tail_ << endl;
    cout << "a: ";
    for (int j = 0; j < 10; ++j) {
      cout << a[a.Size() - 10 + j] << " ";
    }
    cout << endl;

    cout << "b: ";
    for (int j = 0; j < 10; ++j) {
      cout << b[b.size() - 10 + j] << " ";
    }
    cout << endl;

//    int bsize = b.size();
    for (int j = 0; j < b.size(); ++j) {
      if (!REQUIRE(a[j], b[j])) {
        cout << b.size() << " " << a.Size() << " " << j << endl;
        cout << b[j] << " !!!! " << a[j] << " " << a[9967] << " " << b[9967] << endl;
        return 0;
      }

    }
  }
}