# Data-Structures-and-Algorithms
Will cover Data Structures and algorithms related codes written in C++. 
Will be having class of each data structure in .hpp files which can be included when we want to use something. 
There is also a .cpp file which uses this library to test the functionalities. 
The goes has folders src and tests where the src has the library to include and tests folders contains the .cpp files and we include the library there to  test it. 

Data-Structures:
  1. Stack
  2. Queue
  3. Linked-Lists:
    3.1. Singly-Linked-Lists
    3.2. Circular-Linked-Lists
    3.3. Doubly-Linked-Lists

Explanation for the data strctures. 
Stack: 
We make a stack where we the capacity changes has needed through a vector like concept and it drops the last half of the space while calling pop if more than half of the stack is empty to avoid wastage of memory. 

Queue:
We use a vector like concept to store the values. We do not store the things in a circular manner because of this concept in the queue. We will remove the first half of the queue to save the space when it gets empty. 

Linked-Lists:
The try is made to make the linked lists where we can also enforce the rule to make a sorted linked list with the normal one using the same library. 
Eg: Making a normal SinglyLinkedList and sorted SinglyLinkedList of int type:

SinglyLinkedList<int> ls; // Normal list.
SinglyLinkedList<int> lsSorted(true); // Sorted list.
SinglyLinkedList<int> ls(false); // Again a normal list. 

Note: Sorting a linked list does not automatically set the isSortedList boolean has it is the boolean saying if list enforces the sorted insert propoerty or not and not about seeing if the list is sorted at any moment of time or not. 