#include <iostream>
#include <cstring>
using namespace std;

template<class T> class QuickSort {
    private:
        void swap(T* a, T* b) { 
            T t = *a; 
            *a = *b; 
            *b = t; 
        } 
  
        int partition (T* arr, int low, int high, int (*compare)(T a, T b)) { 
            int pivot = arr[high];   
            int i = (low - 1), j; 
  
            for (j = low; j <= high- 1; j++) { 
                if (compare(arr[j], pivot) != 1) { 
                    i++;     
                    swap(&arr[i], &arr[j]); 
                } 
            } 
            swap(&arr[i + 1], &arr[high]); 
            return (i + 1); 
        } 
  
        void quickSort(T* arr, int low, int high, int (*compare)(T a, T b)) { 
            if (low < high) { 
                int pi = partition(arr, low, high, compare); 
  
                quickSort(arr, low, pi - 1, compare); 
                quickSort(arr, pi + 1, high, compare); 
            } 
        } 
    public:
        void sort(T* arr, size_t size, int (*compare)(T a, T b)) {
            quickSort(arr, 0, size - 1, compare);
        }

        T* returnSortedCopy(T* arr, size_t size, int (*compare)(T a, T b)) {
            T* new_arr = new T[size];
            copy(arr, arr + size, new_arr);
            this -> sort(new_arr, size, compare);
            return new_arr;
        } 
};