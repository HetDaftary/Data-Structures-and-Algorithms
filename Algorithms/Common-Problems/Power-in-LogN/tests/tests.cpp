#if defined(_WIN32) || defined(_WIN64) || (defined(__CYGWIN__) && !defined(_WIN32)) // Windows uses a different system for path names. 
    #include "..\includer.hpp"
#else 
    #include "../includer.hpp"
#endif

int main() {
    cout << power(5, 5) << endl;
    cout << power(2, 7) << " " << power(2, 10) << endl;
    return 0;
}