#include "power-in-logn.hpp"

double fibonacci(unsigned int a) {
    return 0.447213595*(power(1.618033989, a) - power(-0.618033989, a));
}