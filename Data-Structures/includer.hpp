#if defined(_WIN32) || defined(_WIN64) || (defined(__CYGWIN__) && !defined(_WIN32)) // Windows uses a different system for path names. 
    #include "Queue\includer.hpp"
    #include "Stack\includer.hpp"
    #include "Linked-Lists\includer.hpp"
#else 
    #include "Queue/includer.hpp"
    #include "Stack/includer.hpp"
    #include "Linked-Lists/includer.hpp"
#endif