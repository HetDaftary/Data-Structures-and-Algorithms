#if defined(_WIN32) || defined(_WIN64) || (defined(__CYGWIN__) && !defined(_WIN32)) // Windows uses a different system for path names. 
    #include "src\Stack.hpp"
#else 
    #include "src/Stack.hpp"
#endif