#if defined(_WIN32) || defined(_WIN64) || (defined(__CYGWIN__) && !defined(_WIN32)) // Windows uses a different system for path names. 
    #include "Sorting-Algorithms\includer.hpp"
    #include "Common-Problems\includer.hpp"
#else 
    #include "Sorting-Algorithms/includer.hpp"
    #include "Common-Problems/includer.hpp"
#endif

