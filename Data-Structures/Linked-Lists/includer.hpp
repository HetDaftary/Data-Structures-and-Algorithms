#if defined(_WIN32) || defined(_WIN64) || (defined(__CYGWIN__) && !defined(_WIN32)) // Windows uses a different system for path names. 
    #include "Singly-Linked-Lists\includer.hpp"
    #include "Doubly-Linked-Lists\includer.hpp"
    #include "Circular-Linked-Lists\includer.hpp"
#else 
    #include "Singly-Linked-Lists/includer.hpp"
    #include "Doubly-Linked-Lists/includer.hpp"
    #include "Circular-Linked-Lists/includer.hpp"
#endif