#if defined(_WIN32) || defined(_WIN64) || (defined(__CYGWIN__) && !defined(_WIN32)) // Windows uses a different system for path names. 
    #include "..\includer.hpp"
#else 
    #include "../includer.hpp"
#endif

int main() {
    MinHeap<int, false> minHeap;

    for (int i = 0; i < 10; i++) {
        minHeap.insert(i);
    }

    cout << minHeap.peek() << endl;

    minHeap.display(cout);

    cout << minHeap.deleteRoot() << endl;  

    minHeap.display(cout);

    return 0;
}