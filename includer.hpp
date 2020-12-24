#if defined(_WIN32) || defined(_WIN64) || (defined(__CYGWIN__) && !defined(_WIN32)) // Windows uses a different system for path names. 
    #include "Data-Structures\includer.hpp"
    #include "Algorithms\includer.hpp"
#else
    #include "Data-Structures/includer.hpp"
    #include "Algorithms/includer.hpp"
#endif