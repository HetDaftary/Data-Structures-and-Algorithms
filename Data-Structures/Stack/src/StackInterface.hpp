#include <iostream>
#include <fstream>

template<class T> class StackInterface {
    public:
        T* arr;
        unsigned int tos, capacity;

        StackInterface(int capacity) {
            this -> arr = new T[capacity];
            this -> tos = 0;
            this -> capacity = capacity;
        }

        bool isEmpty() {
            return this -> tos == 0;
        }

        virtual void push(T key) {}

        T peek() {
            return this -> arr[this -> tos - 1];
        }

        virtual bool pop() {
            return false;
        }

        void displayStack(std::ostream& outStream, std::string sep) {
            for (unsigned int i = 0; i < this -> tos; i++) {
                outStream << this -> arr[i] << sep;
            } outStream << std::endl;
        }
};