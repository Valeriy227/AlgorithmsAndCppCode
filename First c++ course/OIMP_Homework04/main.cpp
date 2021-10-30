//#include <iostream>
//#include <vector>
//#include <ostream>
//#include "J.h"

#include <memory>
#include <iostream>

using namespace std;

int main() {
    shared_ptr<int> sp(new int(42));
    auto sp2 = sp;
    ++*sp;
    cout << sp.use_count() << endl;
    sp2 = nullptr;
    // sp2.reset();
    cout << sp.use_count() << endl;
}
