#if defined(_WIN32) || defined(_WIN64) || (defined(__CYGWIN__) && !defined(_WIN32)) // Windows uses a different system for path names. 
    #include "Max-Heap\includer.hpp"
    #include "Min-Heap\includer.hpp"
#else
    #include "Max-Heap/includer.hpp"
    #include "Min-Heap/includer.hpp"
#endif