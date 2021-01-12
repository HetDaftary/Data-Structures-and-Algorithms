# Functionalities implemented:
* <b>class Node:</b> The private node class helps the list to list to get the node structure to be used.   
* <b>Constructor:</b> The constructor uses default argument for the list and by default it is false. 
* <b>getIsSorted:</b> Getter or accessor method for the isSorted property. 
* <b>setIsSorted:</b> Setter or mutator method for the isSorted property. 
* <b>insert:</b> To insert data in the list. Inserts given data at last if normal list or inserts in sorted manner if sorted insert is enforced.
* <b>insertAtFront:</b> Inserts data at the front of the list. 
* <b>search:</b> Searchs for the given data in the list. 
* <b>deleteOnce:</b> Deletes the first occurence of the data. 
* <b>deleteAll:</b> Deletes all the occurence of the data.
* <b>makeCopy:</b> Returns a copy of the list.
* <b>reverseCopy:</b> Returns the new reversed list. 
* <b>reverse:</b> Reverses the list.
* <b>sort:</b> Sorts the list. 
* <b>getSortedCopy:</b> Returns a new sorted copy of the list. 
* <b>display:</b> Display the elements with given out interface and the separator(default is " "). 

# Some important points:
* <b> You have to make a [compare function](https://github.com/HetDaftary/Data-Structures-and-Algorithms/tree/main/Algorithms/Sorting-Algorithms) to sort</b> the objects of different class easily so you can get the result in the way you want. You can refer to it with the link. 
* The class Node is a private class inside the class of the code. So the list can be easily implemented. 
* The Constructor uses the default argument as false so both <b>SinglyLinkedList<int> ls;</b> and <b>SinglyLinkedList<int>ls(true);</b> act has valid declaration. 
* <b>The isSorted property is to know if the list enforces the sorted insert or not. It is not a variable to see if the list is sorted or not at any time. Yes, isSorted = true means the list is sorted but if false, we need to check. </b>
* The functions <b>insertAtFront and reverse cannot be used if the isSorted is true</b> and will throw exceptions in that case.
* <b>The copies of the list have isSorted to false.</b> irrespective of the original list. 
* We use Merge sort algorithm to do the task in O(nlogn) time.  

# Code Snippets for Examples:
* Make the linked list(We are using SinglyLinkedList for examples but you can change the types.):
  
        SinglyLinkedList<int> ls;
        // Makes a Singly-linked-list.
        
        DoublyLinkedList<int> ls;
        // Makes a Doubly-linked-list.
         
        CircularLinkedList<int> ls;
        // Makes a circular-linked-list.
        
* To know if the list enforces the sorted insert.
        
        bool ans = ls.getIsSorted();
        
* To set the rule for sorted insert:
       
       ls.setIsSorted();
 
* To insert an element in the list:
    
        ls.insert(i);
        
 * To insert the element at front of the list:
 
        ls.insertAtFront(i);

* To serach for an element x in the list:
  
        bool ans = ls.search(x);
        
* To make a copy of the list:
        
        SinglyLinkedList lsCopy = ls.makeCopy();
        
* To delete all the occurances of an element from the list in a single iteration:
        
        ls.deleteAll();
 
* To make a reverse copy of the list where original is unaffected:
    
        SinglyLinkedList lsCopy = ls.reverseCopy();
        
 * Sort the current lsit:
 
        ls.sort();
        
 * To get the sorted copy where original is unaffected:
  
        ls.getSortedCopy();
        
* To display the list:
        
        ls.display(cout);
        
        // OR if you want to write in the file.
        
        ostream fileToWrite;
        ls.display(fileToWrite);
        
* To see the peek(element that will be dequeued.):
        
        int p = qu.peek();
 
* To reverse the list:
    
        ls.reverse();
