#if defined(_WIN32) || defined(_WIN64) || (defined(__CYGWIN__) && !defined(_WIN32)) // Windows uses a different system for path names. 
    #include "..\includer.hpp"
#else 
    #include "../includer.hpp"
#endif

int main() {
    cout << fibonacci(2) << " " << fibonacci(3) << " " << fibonacci(5) << endl;
    return 0;
}