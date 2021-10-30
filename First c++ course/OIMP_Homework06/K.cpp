#include <iostream>
#include "vector"
#include "K.h"

using namespace std;

int main() {
    vector<vector<int>> v = {{1, 2, 3},
                             {4},
                             {5, 6},
                             {}};
    for (const auto x : MakeRange(v)) {
        cout << x << endl;
    }
}