#if defined(_WIN32) || defined(_WIN64) || (defined(__CYGWIN__) && !defined(_WIN32)) // Windows uses a different system for path names. 
    #include "..\includer.hpp"
#else 
    #include "../includer.hpp"
#endif

int main() {
    // Variable size Heap.
    MaxHeap<int, false> maxHeap;

    for (int i = 0; i < 10; i++) {
        maxHeap.insert(i);
    }

    cout << maxHeap.peek() << endl;

    maxHeap.display(cout);

    cout << maxHeap.deleteRoot() << endl;  

    maxHeap.display(cout);

    cout << "\n\nFixed size Heap" << endl;

    // Fixed size heap.
    MaxHeap<int, true> m1(10);

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
    MaxHeap<int, false> m2(arr, 3);
    // First three are the required elements.

    cout << m2.peek() << endl;

    m2.display(cout);

    cout << m2.deleteRoot() << endl;

    m2.display(cout);

    return 0;
}