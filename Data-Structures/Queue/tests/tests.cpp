#if defined(_WIN32) || defined(_WIN64) || (defined(__CYGWIN__) && !defined(_WIN32)) // Windows uses a different system for path names. 
    #include "..\includer.hpp"
#else 
    #include "../includer.hpp"
#endif

int main() {
    // Without fixed size.
    Queue1<int, false> qu;
    for (int i = 0; i < 5; i++) {
        qu.enqueue(i);
        qu.displayQueue(cout);
    }

    while (!qu.isEmpty()) {
        qu.dequeue();
        qu.displayQueue(cout);
    }

    // With Fixed Size.
    Queue1<int, true> qu1(5);
    for (int i = 0; i < 5; i++) {
        qu1.enqueue(i);
        qu1.displayQueue(cout);
    }

    while (!qu1.isEmpty()) {
        qu1.dequeue();
        qu1.displayQueue(cout);
    }

    return 0;
}