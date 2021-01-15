#if defined(_WIN32) || defined(_WIN64) || (defined(__CYGWIN__) && !defined(_WIN32)) // Windows uses a different system for path names. 
    #include "Heaps\includer.hpp"
    #include "Binary-Search-Tree\includer.hpp"
#else 
    #include "Heaps/includer.hpp"
    #include "Binary-Search-Tree/includer.hpp"
#endif