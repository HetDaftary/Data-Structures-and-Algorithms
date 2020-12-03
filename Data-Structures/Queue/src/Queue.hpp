#include <iostream>
using namespace std;

template<class T> class Queue {
    private:
        T* arr;
        int front, rear, capacity;
    public:
        Queue() {
            this -> arr = new T[1];
            this -> front = -1;
            this -> rear = -1;
            this -> capacity = 1;
        }

        Queue(unsigned int initialCapacity) {
            this -> arr = new T[initialCapacity];
            this -> front = -1;
            this -> rear = -1;
            this -> capacity = initialCapacity;
        }

        void enqueue(T key) {
            if (this -> rear == -1) { // Empty queue. 
                arr[0] = key;
                rear = 0;
            } else if (this -> rear == this -> capacity - 1) {
                                
            }
        }

        void dequeue() {

        }
};