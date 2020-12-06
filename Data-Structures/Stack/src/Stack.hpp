#include <iostream>
using namespace std;

template<class T> class Stack {
    private:    
        T* arr;
        unsigned int tos, capacity;
    public:
        /* Constructors for Stack. */
        Stack() { // Creating new empty stack. 
            this -> arr = new T;
            this -> tos = 0;
            this -> capacity = 1;
        }

        Stack(int initialCapacity) {
            this -> arr = new T[capacity];
            this -> tos = 0;
            this -> capacity = initialCapacity;
        }

        /* Methods to be used for the Stack. */
        void push(T key) {
            if (this -> tos == capacity) {
                T* temp_arr = new T[2 * capacity];
                copy(this -> arr, (this -> arr) + capacity, temp_arr);
                delete this -> arr;
                capacity *= 2;
                this-> arr = temp_arr;
            }
            this -> arr[tos++] = key;
        }

        T peek() {
            return this -> arr[tos - 1];
        }

        void pop() {
            if (this -> capacity < 2 * (this-> tos)) {
                T* temp_arr = new T[tos];
                copy(this -> arr, this -> arr + tos, temp_arr);
                delete this -> arr;
                this -> arr = temp_arr;
            } --(this -> tos);
        }

        void displayStack() {
            for (int i = 0; i < this -> tos; i++) {
                cout << this -> arr[i] << " ";
            } cout << endl;
        }
};