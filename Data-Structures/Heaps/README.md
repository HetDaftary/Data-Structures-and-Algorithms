# Functionalities implemented:
* <b>isEmpty:</b> To see if the stack is empty to not right now.
* <b>insert:</b> inserts a key in the Heap. 
* <b>peek:</b> Returns the vlaue of the root but Heap reamains unchanged.
* <b>deleteRoot:</b> Deletes the element at root. 
* <b>displayStack:</b> Displays all the elements in a space separated manner of the Heap to a given out file, "cout" if you want to write to standard out. 

# Some important points:
* We give two options to you related to size of Heap. 
  * Make a fixed size heap where code does not change the size at any time.
  * Make a variable sized heap.
* For making the heap, we have two options.
  * Give the size if fixed size heap.
  * Give array to the code to start with. We copy the array and use it so the original array will be unaffected. 
* If the array is of variable size, we double the size if the array is full while insert function. 
* If more than half of the array is empty when deleting, we half the size if not a fixedsize array.
* Peek function does not change the array

# Code Snippets for Examples:

* Make a fixed size Heap:

        MaxHeap<int, true> maxHeap(5); // Normal heap
        // OR
        MaxHeap<int, true> maxHeap(arr, elementCount); // Making heap using array.

        // To make min heap.
        MinHeap<int, true> minHeap(4); 
        // OR 
        MinHeap<int, true> minHeap(arr, elementCount);

* Make a heap with variable size:
        
        MaxHeap<int, false> maxHeap;
        // OR
        MaxHeap<int, false> maxHeap(arr, elementCount);
        
* To insert data in heap:

        maxHeap.insert(element);
        
* To delete the root element:

        int a = maxHeap.deleteRoot();
          
* Get the element at root:

        int a = maxHeap.peek();
        
* display the stack:

        maxHeap.display(cout); // Display with default separation.
        // OR
        maxHeap.display(cout, "\n"); // Display with \n as separation.
