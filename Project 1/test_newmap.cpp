#include "newmap.h"
#include <cassert>
#include <iostream>

int main() {
    Map a(1000);
    Map b(5);
    Map c;

    std::string k[6] = { "a", "b", "c", "d", "e", "f" };
    double v = 3.14;

    // Insert 5 into b
    for (int n = 0; n < 5; n++) {
        assert(b.insert(k[n], v));
    }

    // Sixth should fail
    assert(!b.insert(k[5], v));

    // Swap test
    a.swap(b);
    assert(!a.insert(k[5], v));  // a now has capacity 5
    assert(b.insert(k[5], v));   // b now has capacity 1000

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
