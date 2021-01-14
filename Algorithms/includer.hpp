#if defined(_WIN32) || defined(_WIN64) || (defined(__CYGWIN__) && !defined(_WIN32)) // Windows uses a different system for path names. 
    #include "Tower-Of-Hanoi\includer.hpp"
    #include "Power-in-LogN\includer.hpp"
    #include "Sorting-Algorithms/includer.hpp"
    #include "Prime-Number-Test/includer.hpp"
    #include "Fibonacci-In-Logn/includer.hpp"
#else 
    #include "Tower-Of-Hanoi/includer.hpp"
    #include "Power-in-LogN/includer.hpp"
    #include "Sorting-Algorithms/includer.hpp"
    #include "Prime-Number-Test/includer.hpp"
    #include "Fibonacci-In-Logn/includer.hpp"
#endif
