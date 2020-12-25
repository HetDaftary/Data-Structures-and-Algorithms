 #if defined(_WIN32) || defined(_WIN64) || (defined(__CYGWIN__) && !defined(_WIN32)) // Windows uses a different system for path names. 
    #include "..\includer.hpp"
#else 
    #include "../includer.hpp"
#endif

int main() {
    Queue<int> qu;
    for (int i = 0; i < 1000; i++) {
        qu.enqueue(i);
        qu.displayQueue(cout);
    }

    while (!qu.isEmpty()) {
        qu.dequeue();
        qu.displayQueue(cout);
    }
    return 0;
}
