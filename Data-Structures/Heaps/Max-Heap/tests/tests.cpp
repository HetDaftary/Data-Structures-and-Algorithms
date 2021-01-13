#if defined(_WIN32) || defined(_WIN64) || (defined(__CYGWIN__) && !defined(_WIN32)) // Windows uses a different system for path names. 
    #include "..\includer.hpp"
#else 
    #include "../includer.hpp"
#endif

int main() {
    MaxHeap<int, false> maxHeap;

    for (int i = 0; i < 10; i++) {
        maxHeap.insert(i);
    }

    cout << maxHeap.peek() << endl;

    maxHeap.display(cout);

    cout << maxHeap.deleteRoot() << endl;  

    maxHeap.display(cout);

    return 0;
}