#include "QueueInterface.hpp"

template<class T> class QueueFixedSize : public QueueInterface<T> {
    public:
        QueueFixedSize(int capacity) : QueueInterface<T>(capacity) {}

        void enqueue(T key) {
            if (this -> front == -1) {
                // Inserting in an empty queue.
                this -> front = 0;
                this -> rear = 0;
                this -> arr[this -> rear] = key; 
            } else if ((this -> rear + 1) % this -> capacity == this -> front) {
                // Queue is full. We cannot insert anymore.
                throw "Overflow";                
            } else {
                this -> rear = (this -> rear + 1) % this -> capacity;
                this -> arr[this -> rear] = key; 
            }
        }   

        bool dequeue() {
            if (this -> front == -1) return false;
            if (this -> front == this -> rear) {
                this -> front = -1;
                this -> rear = -1;
            } else {
                this -> front = ((this -> front) + 1) % this -> capacity;
            } return true;
        }

        void displayQueue(ostream& outStream, std::string sep) {
            if (!(this -> isEmpty())) {
                if (this -> front <= this -> rear) {    
                    for (int i = this -> front; i <= this -> rear; i++) {
                        outStream << this -> arr[i] << sep;
                    } 
                } else {
                    for (int i = this -> front; i < this -> capacity; i++) {
                        outStream << this -> arr[i] << sep;
                    } 
                    for (int i = 0; i <= this -> rear; i++) {
                        outStream << this -> arr[i] << sep;
                    }
                } outStream << endl;
            } 
        }
};

template<class T> class QueueVariableSize : public QueueInterface<T> {
    public:
        QueueVariableSize(int capacity) : QueueInterface<T>(capacity) {}

        void enqueue(T key) {
            if (this -> rear == -1) { // Empty queue. 
                this -> arr[0] = key;
                this -> rear = 0;
                this -> front = 0;
                return;
            } else if (this -> rear == this -> capacity - 1) { // Queue being full.
                T* temp_arr = new T[2 * (this -> capacity)];
                std::copy(this -> arr, (this -> arr) + (this -> capacity), temp_arr);
                this -> arr = temp_arr;
                this -> capacity *= 2;
            } this -> arr[++(this -> rear)] = key;
        }

        bool dequeue() {
            //cout << this -> front << " " << this -> rear << " " << this -> capacity << endl;

            if (this -> front == -1) {
                return false;
            } else {
                if (this -> front == this -> rear) { // Will become empty queue if dequeue. 
                    this -> front = -1;                        
                    this -> rear = -1;
                    //cout << "\n\nMaking empty queue\n\n";
                    delete this -> arr;
                    this -> capacity = 1;
                    this -> arr = new T[this -> capacity];
                } else if ((this -> front != this -> rear) && (this -> capacity > 1) && (2 * this -> front > this -> rear)) { // To make the queue smaller. 
                    T* temp_arr = new T[this -> capacity / 2];
                    //cout << "\n\nEntering the part to half the storage\n\n";                        
                    std::copy((this -> arr) + (this -> front), (this -> arr) + (this -> rear) + 1, temp_arr);                        
                    this -> rear -= this -> front;
                    this -> front = 0;
                    delete this -> arr;
                    this -> arr = temp_arr;
                    (this -> capacity) = (this -> capacity)/ 2;
                } 
            
                this -> front++;
            }return true;
        }

        void displayQueue(ostream& outStream, std::string sep) {
            if (!(this -> isEmpty())) {       
                for (int i = this -> front; i <= this -> rear; i++) {
                    outStream << this -> arr[i] << sep;
                } 
                outStream << endl;
            }
        }
};