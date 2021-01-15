#include <iostream>
#include <fstream>
using namespace std;

/**
 * Trying to get if the number is prime or not in O(logn) time. 
 * Space: O(1).
 */
bool isPrime(unsigned int num) {
    if (num < 2) return false; 

    if (num == 2 || num == 3) return true;

    int i = 2;
    while (i * i <= num) {
        if (num % i == 0) return false;
        i++;
    } return true;
}