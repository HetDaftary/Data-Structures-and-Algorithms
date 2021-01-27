#include "MaxHeap.hpp"
#include "Queue.hpp"

template<class T> class PriorityQueue {
    /* Higher the number of priroty, higher the priority. */
    private:
        class Node {
            public:    
                Queue<T, false>* qu;
                int priority;
            
                Node() {}

                Node(int priority, T key) {
                    this -> priority = priority;
                    this -> qu = new Queue<T, false>;
                    this -> qu -> enqueue(key);
                }

                /* Overloading the operators for MaxHeap class. */
                inline bool operator < (Node& n) {
                    return (this -> priority < n.priority);
                } 

                inline bool operator > (Node& n) {
                    return (this -> priority > n.priority);
                }

                inline bool operator == (Node& n) {
                    return (this -> priority == n.priority);
                }

                inline bool operator <= (Node& n) {
                    return (this -> priority <= n.priority);
                }

                inline bool operator >= (Node& n) {
                    return (this -> priority >= n.priority);
                }
        };

        MaxHeap<Node, false> heap;
    public:
        PriorityQueue() {}
        
        bool isEmpty() {
            return heap.isEmpty();
        }

        void enqueue(T key, int priority) {
            int index = heap.search(priority);

            if (index > -1) {
                // Queue exists in the heap.
                heap.arr[index].qu -> enqueue(key);
            } else {
                heap.insert(Node(priority, key));
            }
        }

        T peek() {
            if (heap.isEmpty()) {
                throw "UnderFlow";
            } else {
                return heap.arr[0].qu -> peek();
            }
        }

        void dequeue() {
            if (!heap.isEmpty()) {
                heap.arr[0].qu -> dequeue();
                if (heap.arr[0].qu -> isEmpty()) {
                    heap.deleteRoot();
                    // Because we want to remove the empty queue for getting things done without errors.
                }
            }
        }

        void displayQueue(ostream& outStream, string sep = " ") {
            heap.display(outStream, sep);
        }
};