#if defined(_WIN32) || defined(_WIN64) || (defined(__CYGWIN__) && !defined(_WIN32)) // Windows uses a different system for path names. 
    #include "Quick-Sort\includer.hpp"
    #include "Merge-Sort\includer.hpp"
    #include "Insertion-Sort\includer.hpp"
    #include "Bubble-Sort\includer.hpp"
#else 
    #include "Quick-Sort/includer.hpp"
    #include "Merge-Sort/includer.hpp"
    #include "Insertion-Sort/includer.hpp"
    #include "Bubble-Sort/includer.hpp"
#endif
