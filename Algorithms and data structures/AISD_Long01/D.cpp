#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

class SegmentTree {
public:
   int n;
   vector<int> data;
   SegmentTree(int _n) {
       n = _n;
       data.resize(4 * n);
   }

   void set(int index,
           int current_vertex = 1, int segment_left = 0, int segment_right = -1) {
       if (segment_right == -1) {
           segment_right = n;
       }
       if (segment_left + 1 == segment_right) {
           data[current_vertex] = 1;
           return;
       }

       int middle = (segment_left + segment_right) / 2;
       if (index < middle) {
           set(index, current_vertex * 2, segment_left, middle);
       } else {
           set(index, current_vertex * 2 + 1, middle, segment_right);
       }
       data[current_vertex] = data[current_vertex * 2] +
               data[current_vertex * 2 + 1];
   }

   int get_sum(int request_left, int request_right,
           int current_vertex = 1, int segment_left = 0, int segment_right = -1) {
       if (segment_right == -1) {
           segment_right = n;
       }
       if (request_left == segment_left && request_right == segment_right) {
           return data[current_vertex];
       }
       if (request_left >= request_right) {
           return 0;
       }

       int middle = (segment_left + segment_right) / 2;
       return get_sum(request_left, min(middle, request_right),
               current_vertex * 2, segment_left, middle) +
       get_sum(max(middle, request_left), request_right,
               current_vertex * 2 + 1, middle, segment_right);
   }
};

vector<int> get_arrival_numbers(ll n, ll distance, vector<ll>& speed) {
   vector<pair<ll, int>> real_time(n);
   for (int i = 0; i < n; ++i) {
       real_time[i] = {speed[i] * distance + i, i};
   }
   sort(real_time.begin(), real_time.end());

   vector<int> arrival_numbers(n);
   for (int i = 0; i < n; ++i) {
       arrival_numbers[real_time[i].second] = i;
   }
   return arrival_numbers;
}

ll get_passing_count(int n, vector<int>& arrival) {
   ll ans = 0;
   SegmentTree segment_tree(n);
   for (int i = 0; i < n; ++i) {
       ans += segment_tree.get_sum(arrival[i] + 1, n);
       segment_tree.set(arrival[i]);
   }
   return ans;
}

int main() {
   ll n, distance;
   cin >> n >> distance;
   vector<ll> speed(n);
   for (ll& i : speed) {
       cin >> i;
   }
   auto arrival = get_arrival_numbers(n, distance, speed);
   cout << get_passing_count(n, arrival) << endl;
}