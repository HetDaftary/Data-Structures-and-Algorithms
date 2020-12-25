#include <iostream>
#include <fstream>
using namespace std;

void towers(int num, string from, string to, string aux, ostream& outStream) {    
    if (num < 2) { // Base case.
        outStream << "Move disk 1 from " <<  from << " to " << to << endl;
        return;
    }
    towers(num - 1, from, aux, to, outStream);
    outStream << "Move disk " << num << " from " << from << " to " << to << endl;
    towers(num - 1, aux, to, from, outStream);
}