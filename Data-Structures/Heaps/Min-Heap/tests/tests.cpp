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

    cout << "\n\nFixed size Heap" << endl;

    // Fixed size heap.
    MinHeap<int, true> m1(10);

    for (int i = 0; i < 10; i++) {
        m1.insert(i);
    }

    cout << m1.peek() << endl;

    m1.display(cout);

    cout << m1.deleteRoot() << endl;

    m1.display(cout);

    cout << "\n\nHeap using array" << endl;

    // Make variable heap from array.
    int arr[5] = {1, 2, 3, 0, 0};
    MinHeap<int, false> m2(arr, 3);
    // First three are the required elements.

    cout << m2.peek() << endl;

    m2.display(cout);

    cout << m2.deleteRoot() << endl;

    m2.display(cout);
    return 0;
}