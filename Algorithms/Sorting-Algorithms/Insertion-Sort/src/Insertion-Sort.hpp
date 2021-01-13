#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

template<class T> class InsertionSort {
    private:
        void insertionSort(T* arr, size_t n, int (*compare)(T a, T b)) {  
            int i, j;  
            T key;
            for (i = 1; i < n; i++) {  
                key = arr[i];  
                j = i - 1;  
  
                while (j >= 0 && compare(arr[j], key) == 1) {  
                    arr[j + 1] = arr[j];  
                    j = j - 1;  
                }  
                arr[j + 1] = key;  
            }  
        }  
    public:
        void sort(T* arr, size_t size, int (*compare)(T a, T b)) {
            insertionSort(arr, size, compare);
        }

        T* returnSortedCopy(T* arr, size_t size, int (*compare)(T a, T b)) {    
            T* new_arr = new T[size];
            copy(arr, arr + size, new_arr);
            this -> sort(new_arr, size, compare);
            return new_arr;
        }
};