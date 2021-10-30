#include <iomanip>
#include <iostream>
#include <random>
#include <ctime>

using namespace std;

double rand_double(double a, double b) {
    static default_random_engine gen;
    static uniform_real_distribution<double> distr(a, b);
    return distr(gen);
}

vector<double> randp() {
    vector<double> p = {rand_double(0, 100), rand_double(0, 100), rand_double(0, 100)};
    return p;
}

bool contains(vector<int>& buble, vector<double>& p) {
    auto x = buble[0] - p[0];
    auto y = buble[1] - p[1];
    auto z = buble[2] - p[2];
    return x * x + y * y + z * z <= buble[3] * buble[3];
}

int main() {
    clock_t start = clock();

    int n;
    cin >> n;
    vector<vector<int>> bubles(n, vector<int>(4));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> bubles[i][j];
        }
    }

    int total = 0;
    int ok = 0;
    while (true) {
        for (int i = 0; i < 100; ++i) {
            total++;
            auto p = randp();
            // cout << p[0] << " " << p[1] << " " << p[2] << endl;
            for (auto& buble : bubles) {
                if (contains(buble, p)) {
                    ok++;
                    break;
                };
            }
        }
        if ((double)(clock() - start) / CLOCKS_PER_SEC > 1.97) {
            break;
        }
    }
 
    cout << fixed << setprecision(5) << (double) ok / total << endl;
}