#include <iostream>
#include <cstring>
using namespace std;

template<class T> class BubbleSort {
    private:
        /* Swaps value of a and b. */
        void swap(T* a, T* b) {
            T temp = *a;
            *a = *b;
            *b = temp;
        }

    public:
        /* Sorts this array. */
        void sort(T* arr, size_t size, int (*compare)(T a, T b)) {
            size_t i, j; // iterator. 

            for (i = 0; i < size - 1; i++) {
                for (j = 0; j < size - i - 1; j++) {
                    if (compare(arr[j], arr[j + 1]) == 1) {
                        swap(&arr[j], &arr[j + 1]);
                    }
                }
            }
        }

        /* Returns a sorted array. Original one remains unaffected. */
        T* returnSortedCopy(T* arr, size_t size, int (*compare)(T a, T b)) {
            
            T* new_arr = new T[size];
            copy(arr, arr + size, new_arr);
            this -> sort(new_arr, size, compare);
            return new_arr;
        }
};