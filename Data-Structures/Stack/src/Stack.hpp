#include <iostream>
#include <fstream>
using namespace std;

template<class T, bool isFixedSize> class Stack {
    private:    
        T* arr;
        unsigned int tos, capacity;
    public:
        /* Constructors for Stack. */
        Stack(int initialCapacity = 1) {
            this -> arr = new T[initialCapacity];
            this -> tos = 0;
            this -> capacity = initialCapacity;
        }
    
        /* is Empty function. */
        bool isEmpty() {
            return (this -> tos != 0);
        }

        /* Methods to be used for the Stack. */
        void push(T key) {
            if (isFixedSize) {
                if (this -> tos == capacity) throw "Overflow";
            } else { 
                if (this -> tos == capacity) {
                    T* temp_arr = new T[2 * capacity];
                    copy(this -> arr, (this -> arr) + capacity, temp_arr);
                    delete this -> arr;
                    capacity *= 2;
                    this-> arr = temp_arr;
                }
            }
            this -> arr[tos++] = key;
        }

        T peek() {
            return this -> arr[tos - 1];
        }

        void pop() {
            if (isFixedSize) {
                if (tos == 0) throw "Underflow";
            } else {
                if (this -> capacity < 2 * (this-> tos)) {
                    T* temp_arr = new T[tos];
                    copy(this -> arr, this -> arr + tos, temp_arr);
                    delete this -> arr;
                    this -> arr = temp_arr;
                } 
            }
            --(this -> tos);
        }

        void displayStack(ostream& outStream, string sep = " ") {
            for (int i = 0; i < this -> tos; i++) {
                outStream << this -> arr[i] << sep;
            } outStream << endl;
        }
};
