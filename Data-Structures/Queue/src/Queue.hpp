#include <iostream>
using namespace std;

template<class T> class Queue {
    private:
        T* arr;
        unsigned int front, rear, capacity;
    public:
        Queue() {
            this -> arr = new T[1];
            this -> front = 0;
            this -> rear = 0;
            this -> capacity = 1;
        }

        Queue(unsigned int initialCapacity) {
            this -> arr = new T[1];
            this -> front = 0;
            this -> rear = 0;
            this -> capacity = 1;
        }

        void enqueue() {

        }

        void dequeue() {

        }
};