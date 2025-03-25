#include "map.h"
#include <iostream>
#include <cassert>
using namespace std;

int main() {
    Map gpas;
    gpas.insert("Fred", 2.956);
    assert(!gpas.contains(""));
    gpas.insert("Ethel", 3.538);
    gpas.insert("", 4.000);
    gpas.insert("Lucy", 2.956);
    assert(gpas.contains(""));
    gpas.erase("Fred");
    assert(gpas.size() == 3 && gpas.contains("Lucy") &&
        gpas.contains("Ethel") && gpas.contains(""));
    
	KeyType k;
    ValueType v;

    assert(gpas.get(1, k, v) && k == "Ethel");
	assert(gpas.get("Lucy", v) && v == 2.956);
	gpas.insertOrUpdate("Lucy", 3.538);
	assert(gpas.get("Lucy", v) && v == 3.538);
	gpas.insertOrUpdate("Ricky", 4.000);
	assert(gpas.size() == 4 && gpas.contains("Lucy") &&
		gpas.contains("Ethel") && gpas.contains("Ricky") &&
		gpas.contains(""));
	gpas.erase("Lucy");
	assert(gpas.size() == 3 && gpas.contains("Ethel") &&
		gpas.contains("Ricky") && gpas.contains(""));
	gpas.erase("Ethel");
	gpas.erase("Ricky");
	gpas.erase("");
	assert(gpas.size() == 0);
	cout << "Passed all tests" << endl;
	return 0;
}
