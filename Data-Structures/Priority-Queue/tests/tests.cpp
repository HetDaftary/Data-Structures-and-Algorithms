#if defined(_WIN32) || defined(_WIN64) || (defined(__CYGWIN__) && !defined(_WIN32)) // Windows uses a different system for path names. 
    #includer "..\includer.hpp"
#else 
    #include "../includer.hpp"
#endif

int main() {
    PriorityQueue<int> pq;

    for (int i = 1; i < 4; i++) {
        // I gives the priority here.

        for (int j = 1; j < 4; j++) {
            // J gives the value.

            pq.enqueue(i, j);
        }
    }

    pq.displayQueue(cout);

    while (!pq.isEmpty()) {
        cout << "Peek of the qu: " << pq.peek() << endl; 
        pq.displayQueue(cout);
        pq.dequeue();
        cout << endl << endl;   
    }

    return 0;
}