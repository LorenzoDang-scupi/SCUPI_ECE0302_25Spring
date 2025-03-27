#include "gamermap.h"
#include <iostream>
#include <cassert>


int main() {
	gamermap gm;

    assert(gm.addGamer("Alice"));
    assert(gm.addGamer("Bob"));
    assert(!gm.addGamer("Alice"));
    
    assert(gm.numGamers() == 2);

    assert(gm.hoursSpent("Alice") == 0.0);
    assert(gm.hoursSpent("Charlie") == -1.0); 

    assert(gm.play("Alice", 5.5)); 
    assert(gm.hoursSpent("Alice") == 5.5);
    assert(!gm.play("Charlie", 3.0)); 
    assert(!gm.play("Alice", -2.0)); 

    std::cout << "Expected output: Alice 5.5, Bob 0.0\n";
    gm.print();

    std::cout << "Passed all tests!" << std::endl;
    return 0;
}
