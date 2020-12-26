#include <iostream>
#include <cstring>
using namespace std;

template<class T> class MergeSort {
    private:
        void merge(T* arr, int l, int m, int r, int (*compare)(T a, T b)) {
            int n1 = m - l + 1;
            int n2 = r - m;
 
            T L[n1], R[n2];
 
            for (int i = 0; i < n1; i++) {
                L[i] = arr[l + i];
            }
            for (int j = 0; j < n2; j++) {
                R[j] = arr[m + 1 + j];
            }
 
            int i = 0, j = 0, k = l;
 
            while (i < n1 && j < n2) {
                if (compare(L[i], R[j]) != 1) {
                    arr[k] = L[i];
                    i++;
                } else {
                    arr[k] = R[j];
                    j++;
                }
                k++;
            }
 
            while (i < n1) {
                arr[k] = L[i];
                i++;
                k++;
            }
 
            while (j < n2) {
                arr[k] = R[j];
                j++;
                k++;
            }
        }
 
        void mergeSort(T* arr, int l, int r, int (*compare)(T a, T b)) {
            if(l>=r) {
                return;
            }
            int m = (l+r-1)/2;
            mergeSort(arr,l,m, compare);
            mergeSort(arr,m+1,r, compare);
            merge(arr,l,m,r, compare);
        }
    public:
        void sort(T* arr, size_t size, int (*compare)(T a, T b)) {
            mergeSort(arr, 0, size - 1, compare);
        }

       T* returnSortedCopy(T* arr, size_t size, int (*compare)(T a, T b)) {
            
            T* new_arr = new T[size];
            copy(arr, arr + size, new_arr);
            this -> sort(new_arr, size, compare);
            return new_arr;
        } 
};