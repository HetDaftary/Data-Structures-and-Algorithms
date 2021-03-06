#if defined(_WIN32) || defined(_WIN64) || (defined(__CYGWIN__) && !defined(_WIN32)) // Windows uses a different system for path names. 
    #include "..\include.hpp"
#else 
    #include "../includer.hpp"
#endif

int compareFunction(size_t a, size_t b) {
    if (a > b) return 1;
    if (a == b) return 0;
    return -1;
}

int compareFunctionDescending(size_t a, size_t b) {
    return -1 * compareFunction(a, b);
}

int main() {
    size_t arr[] = {1, 2, 4, 3};
    size_t size = 4;
    int i;

    BubbleSort<size_t> sortObject;

    cout << "Before sorting: ";
    for (i = 0; i < 4; i++) cout << arr[i] << " ";
    cout << endl;

    sortObject.sort(arr, 4, compareFunction);
    cout << "Sorting in ascending order: ";
    for (i = 0; i < 4; i++) cout << arr[i] << " ";
    cout << endl;

    sortObject.sort(arr, 4, compareFunctionDescending);
    cout << "Sorting in descending order: ";
    for (i = 0; i < 4; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}