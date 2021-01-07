#include <iostream>
#include <fstream>
using namespace std;

template<class T, bool isFixedSize> class Queue {
    private:
        T* arr;
        int front, rear, capacity;
    public:
        Queue(int initialCapacity = 1) {
            this -> arr = new T[initialCapacity];
            this -> front = -1;
            this -> rear = -1;
            this -> capacity = initialCapacity;
        }

        bool isEmpty() {
            return (front == -1);
        }

        void enqueue(T key) {
            if (isFixedSize) {    
                if (this -> front == -1) {
                    // Inserting in an empty queue.
                    this -> front = 0;
                    this -> rear = 0;
                    arr[this -> rear] = key; 
                } else if ((this -> rear + 1) % capacity == this -> front) {
                    // Queue is full. We cannot insert anymore.
                    throw "Overflow";
                } else {
                    this -> rear = (this -> rear + 1) % capacity;
                    arr[this -> rear] = key; 
                }
            } else {
                if (this -> rear == -1) { // Empty queue. 
                    arr[0] = key;
                    rear = 0;
                    front = 0;
                    return;
                } else if (this -> rear == this -> capacity - 1) { // Queue being full.
                    T* temp_arr = new T[2 * (this -> capacity)];
                    copy(this -> arr, (this -> arr) + (this -> capacity), temp_arr);
                    this -> arr = temp_arr;
                    this -> capacity *= 2;
                } this -> arr[++rear] = key;
            }
        }

        bool dequeue() {           
            if (isFixedSize) {
                if (isEmpty()) {
                    return false;
                } else if (this -> front == this->rear) {
                    // Queue will become empty after this operation.
                    this -> front = -1;
                    this -> rear = -1;
                } else {
                    this -> front = (this -> front + 1) % capacity;
                } return true;
            } else { 
                /* If the first half is empty, we chop it away. */
                if (!isEmpty()) {
                    if (front == rear) { // Will become empty queue if dequeue. 
                        front = -1;
                        rear = -1;
                        // cout << "\n\nMaking empty queue\n\n";
                        this -> arr = new T[1];
                        return true;
                    } else if ((front != rear) && (capacity > 1) && (2 * front > rear)) { // To make the queue smaller. 
                        T* temp_arr = new T[capacity / 2];
                        // cout << "\n\nEntering the part to half the storage\n\n";
                        copy((this -> arr) + (this -> front), (this -> arr) + (this -> rear) + 1, temp_arr);
                        rear -= front;
                        front = 0;
                        delete this -> arr;
                        this -> arr = temp_arr;
                        (this -> capacity) = (this -> capacity)/ 2;
                    } 
            
                    front++;
                } else {
                    return false;
                } 
            } 
            return true;
        }

        T peek() {
            if (rear == -1) throw "Empty Queue";
            return this -> arr[front];
        } 

        void displayQueue(ostream& outStream, string sep = " ") {
            if (!isEmpty()) {    
                for (int i = front; i <= rear; i++) {
                    outStream << this -> arr[i] << sep;
                } outStream << endl;
            }

            // To code more
            // cout << this -> capacity << " front: " << this -> front << " rear: " << this -> rear << endl;
        }
};
