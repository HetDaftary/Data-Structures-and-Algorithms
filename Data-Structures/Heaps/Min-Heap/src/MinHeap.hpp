#include <iostream>
#include <fstream>
using namespace std;

template<class T, bool isFixedSize> class MinHeap {
    private:
        T* arr;
        int capacity, elementCount;

        void swap(T* a, T* b) {
            T temp = *a;
            *a = *b;
            *b = temp;
        }

        void insertWithoutSpaceManagement(T key) {
            this -> arr[this -> elementCount] = key;
            int parent = (this -> elementCount - 1) / 2, child = this -> elementCount;
            (this -> elementCount)++;
            
            while (this -> arr[parent] > this -> arr[child]) {
                swap(&(this -> arr[parent]), &(this -> arr[child]));
                // Reference based swap function of c++.

                child = parent;
                parent = (child - 1) / 2; 
            }
        }

        void helperForDelete(int root, int left, int right) {
            if ((left < (this -> elementCount)) && (this -> arr[left]) < (this -> arr[root])) {
                swap(&(this -> arr[root]), &(this -> arr[left]));
                helperForDelete(left, 2 * left + 1, 2 * left + 2);
            } else if ((right < (this -> elementCount)) && ((this -> arr[right]) < (this -> arr[root]))) {
                swap(&(this -> arr[root]), &(this -> arr[right]));
                helperForDelete(right, 2 * right + 1, 2 * right + 2);
            } 
        }

        T deleteWithoutSpaceManagement() {
            T to_return = this -> arr[0];

            swap(&(this -> arr[elementCount - 1]), &(this -> arr[0]));
            (this -> elementCount)--;

            helperForDelete(0, 1, 2);            

            return to_return;
        }
    public:
        /** 
         * We give two functionalities for making a here. 
         * - You can have a size to make a MaxHeap. 
         * - Or, you can just pass a arr and make things done with it. 
         */
        MinHeap(int size = 1) {
            this -> capacity = size;
            this -> arr = new T[this -> capacity];
            this -> elementCount = 0;
        }

        MinHeap(T* arr, int elementCount) {
            // MaxHeap constructor will make a MaxHeap of a copy of the array passed. 
            // It will not change the original array.
            // If you pass the element count.

            if (arr == NULL && isFixedSize) throw "Not a valid case";
            if (arr == NULL) throw "Cannot pass NULL here."; 
            this -> capacity = sizeof(arr)/sizeof(arr[0]); 
            // Getting size of the arr.
            this->arr = new T[this-> capacity];
            copy(arr, arr + this -> capacity, this -> arr);
            this -> elementCount = elementCount;
        }

        bool isEmpty() {
            return (this -> elementCount == 0);
        }

        // Inserts a key in the heap.
        void insert(T key) {
            if (isFixedSize && this -> capacity == this -> elementCount) {
                throw "Overflow";
            } else if (!isFixedSize && this -> capacity == this -> elementCount) {
                T* temp_arr = new T[2 * this -> capacity];

                copy(this -> arr, this -> arr + this -> capacity, temp_arr);
                delete this -> arr;

                this->arr = temp_arr;
                this -> capacity *= 2;
            }
            insertWithoutSpaceManagement(key); 
        }

        // Searches for a key in the heap
        T peek() {
            return this -> arr[0];
        }

        // Deletes the root.
        T deleteRoot() {
            if (this -> elementCount == 0) throw "Underflow";

            if (!isFixedSize && this -> capacity > 2 * (this -> elementCount - 1)) {
                T* temp_arr = new T[this -> capacity / 2];

                copy(this -> arr, this -> arr + this -> elementCount, temp_arr);
                delete this -> arr;

                this -> arr = temp_arr;
            }

            return deleteWithoutSpaceManagement();            
        }

        void display(ostream& outStream, string sep = " ") {
            for (int i = 0; i < this -> elementCount; i++) {
                outStream << this -> arr[i] << sep;
            } outStream << endl;
        }
};