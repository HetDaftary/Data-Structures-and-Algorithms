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

        Queue(int initialCapacity) {
            this -> arr = new T[initialCapacity];
            this -> front = -1;
            this -> rear = -1;
            this -> capacity = initialCapacity;
        }

        void enqueue(T key) {
            if (this -> rear == -1) { // Empty queue. 
                arr[0] = key;
                rear = 0;
                front = 0;
                return;
            } else if (this -> rear == this -> capacity - 1) { // Queue being full.
                T* temp_arr = new T[2 * (this -> capacity)];
                copy(this -> arr, (this -> arr) + (this -> capacity), temp_arr);
                del this -> arr;
                this -> arr = temp_arr;
                this -> capacity *= 2;
            } this -> arr[++rear] = key;
        }

        void dequeue() {
            /* If the first half is empty, we chop it away. */

            if (capacity > 1 && front > capacity / 2) { // To make the queue smaller. 
                T* temp_arr = new T[capacity / 2];
                copy((this -> arr) + (this -> front), (this -> arr) + (this -> rear) + 1, this -> temp_arr);
                rear -= front;
                front = 0;
                del arr;
                this -> arr = temp_arr;
            } else if (front == rear) { // Will become empty queue if dequeue. 
                front = -1;
                rear = -1;
                del this -> arr;
                this -> arr = new T[1];
                return;
            }
            
            front++;
        }

        T peek() {
            if (rear == -1) throw "Empty Queue";
            return this -> arr[front];
        } 

        void displayQueue() {
            for (int i = front; i < rear; i++) {
                cout << this -> arr[i] << " ";
            } cout << endl << this -> capacity << endl;
        }
};