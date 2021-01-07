#include <iostream>
#include <cstring>
using namespace std;

template<class T> class HeapSort {
    private:
        void swap(T* a, T* b) {
            T t = *a;
            *a = *b;
            *b = t;
        }

        
    public:
        void sort(T* arr, size_t size, int (*compare)(T a, T b)) {
            
        }

        T* returnSortedCopy(T* arr, size_t size, int (*compare)(T a, T b)) {
            T* new_arr = new T[size];
            copy(arr, arr + size, new_arr);
            this -> sort(new_arr, size, compare);
            return new_arr;
        } 
};