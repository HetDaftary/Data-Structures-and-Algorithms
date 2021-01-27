#include <iostream>
#include <fstream>

template<class T> class QueueInterface {
    public:
        T* arr;
        int front, rear, capacity;
    
        QueueInterface(int capacity) {
            this -> capacity = capacity;
            this -> front = -1;
            this -> rear = -1;
            this -> arr = new T[capacity];
        }  

        bool isEmpty() {
            return (this -> rear == -1);
        }

        virtual void enqueue(T key) {}

        virtual bool dequeue() {
            return 4; // This needs to be over ridden.
        }

        T peek() {
            if (this -> front == -1) {
                throw "Underflow";
            } return this -> arr[0];
        }

        virtual void displayQueue(ostream& outStream, std::string sep) {}
};