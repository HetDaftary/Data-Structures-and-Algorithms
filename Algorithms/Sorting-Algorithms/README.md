# Functionalities implemented:
* <b>sort:</b> The function takes some arguments and sorts the stuff. 
* <b>returnSortedCopy:</b> The function returns a new copy of the Array object which is sorted and the orginial one remains unaffected. 

# Some important points:
* <b>Unlike other algorithm codes, it uses a class for each sorting method.</b>
* It asks for a <b>compare</b> function which is a signnum function used to compare things. 
* compare(a, b) should return 0 when the objects a and b are equal.
* For normal sort, (i.e. sorting in ascending order.) The compare should return 1 when a > b and -1 when b < a.  
* The sorting algorithms here just sort the arrays. If you want to sort liked lists, go the [linked-lists](https://github.com/HetDaftary/Data-Structures-and-Algorithms/tree/main/Data-Structures/Linked-Lists) section and get the algorithms. Take the sort and private methods which help the sort. 

Example:     

    BubbleSort<int> sortObject;
    int arr[] = {1, 2, 4, 3};
    sortObject.sort(arr, 4, compare_function);
    
Compare_function:

    int compare_function(int a, int b) {
        if (a > b) return 1;
        if (a == b) return 0;
        return -1;
    }  

# Details to note for compare_function:
* You can directly use compare function if you want to sort in reverse way as you can just make a function to multiply -1 to compare_function. You can also see the snippets from the test code. 
* Return type: int
* Argument type is same as type given to bubble sort. 

# Types of Sorting algorithms available: 
* Bubble Sort: Time: <b>O(n^2)</b>, Space: <b>O(1)</b>
* Merge Sort: Time: <b>O(n*log(n))</b>, Space: <b>O(n)</b>
* Quick Sort: Time: <b>O(n^2) in worst case, Average: O(n*log(n))</b>, Space: <b>O(n)</b>
* Heap Sort: Time: <b>O(n*log(n))</b>, Space: <b>O(1)</b>
