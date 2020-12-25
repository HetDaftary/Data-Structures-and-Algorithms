# Functionalities implemented:
<b>Sort function:</b> The function takes some arguments and sorts the stuff. 
<b>Return Sorted copy:</b> The function returns a new copy of the Array object which is sorted and the orginial one remains unaffected. 

# Some important points:
* <b>Unlike other algorithm codes, it uses a class for each sorting method.</b>
* It asks for a <b>compare</b> function which is a signnum function used to compare things. 
* compare(a, b) should return 0 when the objects a and b are equal.
* For normal sort, (i.e. sorting in ascending order.) The compare should return 1 when a > b and -1 when b < a.  
* The sorting algorithms here just sort the arrays. If you want to sort liked lists, go the [linked-lists](https://github.com/HetDaftary/Data-Structures-and-Algorithms/tree/main/Data-Structures/Linked-Lists) section and get the algorithms. Take the sort and private methods which help the sort. 
* Example: 

    BubbleSort<int> sortObject;
    int arr[] = {1, 2, 4, 3};
    sortObject.sort(arr, compare_function);

Compare_function:

    int compare_function(int a, int b) {
        if (a > b) return 1;
        if (a == b) return 0;
        return -1;
    }  
