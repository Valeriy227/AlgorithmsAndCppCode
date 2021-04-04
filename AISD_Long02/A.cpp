//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//typedef long long ll;
//
//class Hash {
//public:
//    int n;
//    ll p = 31;
//    ll mod = 200720077;
//    vector<ll> powers;
//    vector<ll> hash_pref;
//
//    Hash(string& s) {
//        n = s.size();
//        powers.resize(n + 1, 1);
//        for (int i = 0; i < n; ++i) {
//            powers[i + 1] = powers[i] * p % mod;
//        }
//        hash_pref.resize(n + 1);
//        for (int i = 0; i < n; ++i) {
//            hash_pref[i + 1] = (hash_pref[i] * p + (s[i] - 'a' + 1)) % mod;
//        }
//    }
//
//    ll get_hash(int l, int r) {
//        return (hash_pref[r] - powers[r - l] * hash_pref[l] % mod + 2 * mod) % mod;
//    }
//};
//
//int compare(int l1, int r1, int l2, int r2, string& s, Hash& hash) {
//    int len1 = r1 - l1, len2 = r2 - l2;
//    int lb = 0, rb = min(len1, len2) + 1;
//    while (lb + 1 < rb) {
//        int mid = (lb + rb) / 2;
//        if (hash.get_hash(l1, l1 + mid) == hash.get_hash(l2, l2 + mid)) {
//            lb = mid;
//        } else {
//            rb = mid;
//        }
//    }
//
//    if (lb == len1 || lb == len2) {
//        if (len1 < len2) {
//            return -1;
//        } else if (len1 == len2) {
//            return 0;
//        } else {
//            return 1;
//        }
//    } else {
//        if (s[l1 + lb] < s[l2 + lb]) {
//            return -1;
//        } else if (s[l1 + lb] == s[l2 + lb]) {
//            return 0;
//        } else {
//            return 1;
//        }
//    }
//}
//
//int main() {
//    cin.tie(0);
//    ios_base::sync_with_stdio(0);
//    string s;
//    cin >> s;
//    Hash hash(s);
//    int m;
//    cin >> m;
//    for (int i = 0; i < m; ++i) {
//        int l1, r1, l2, r2;
//        cin >> l1 >> r1 >> l2 >> r2;
//        cout << compare(l1, r1 + 1, l2, r2 + 1, s, hash) << "\n";
//    }
//}
