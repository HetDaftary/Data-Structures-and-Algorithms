#include "StackInterface.hpp"

template<class T> class StackFixedSize : public StackInterface<T> {
    public:
        StackFixedSize(int capacity) : StackInterface<T>(capacity) {}

        void push(T key) {
            if (this -> tos == this -> capacity) throw "Overflow";

            this -> arr[(this -> tos)++] = key;
        }

        bool pop() {
            if (this -> tos == 0) return false;

            (this -> tos)--;
            return true;
        }
};

template<class T> class StackVariableSize : public StackInterface<T> {
    public:
        StackVariableSize(int capacity) : StackInterface<T>(capacity) {}

        void push(T key) {
            if (this -> tos == this -> capacity) {
                T* temp_arr = new T[2 * this -> capacity];
                std::copy(this -> arr, (this -> arr) + this -> tos, temp_arr);
                delete this -> arr;
                this -> capacity *= 2;
                this-> arr = temp_arr;
            } this -> arr[(this -> tos)++] = key;
        }

        bool pop() {
            if (this -> tos == 0) return false;

            if (2 * (this-> tos) < this -> capacity) {
                this -> capacity /=2;
                T* temp_arr = new T[this -> capacity];
                std::copy(this -> arr, this -> arr + this -> tos, temp_arr);
                delete this -> arr;
                this -> arr = temp_arr;
            } --(this -> tos);
            return true;
        }
};