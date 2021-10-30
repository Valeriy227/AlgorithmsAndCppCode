#import <bits/stdc++.h>

using namespace std;

int main() {
    long double x, y, r;
    cin >> x >> y >> r;
    auto p = log(x * x + y * y);
    cout << fixed << setprecision(15) << p * M_PI * r * r << endl;
}