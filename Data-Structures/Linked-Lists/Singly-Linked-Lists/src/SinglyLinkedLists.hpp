#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

template<class T> class SinglyLinkedList {
    private:
        /* The Node class we should use for making the node. */
        class Node {
            public:
                /* The data is public so we do not need any getters or setters. */
                T data;
                Node* next;

                /**
                 * Methods to access the data.
                 * Only creating Constructor for now.
                 */
                Node(T data) { 
                    this -> data = data;
                }
        };

        /* The data of the list. */
        Node* head;
        bool isSorted;
        /**
         * If true, the list will force the entry of the elements in a sorted manner. 
         * But, It does not mean that if is sorted is false, the list cannot be sorted at any time. 
         * The is sorted property is about the rules to force on the insertion and not about if the list is sorted or not a given moment of time.   
         */

        /* The private methods go here related to our list go here. */

        /* Helper methods for the sorting of our list. */
        Node* sortedMerge(Node* a, Node* b) { 
            Node* result = NULL; 
  
            if (a == NULL) return (b); 
            else if (b == NULL) return (a); 
  
            if (a->data <= b->data) { 
                result = a; 
                result->next = sortedMerge(a->next, b); 
            } else { 
                result = b; 
                result->next = sortedMerge(a, b->next); 
            } 
            return (result); 
        } 

        void frontBackSplit(Node* source, Node** frontRef, Node** backRef) { 
            Node* fast; 
            Node* slow; 
            slow = source; 
            fast = source->next; 
  
            /* Advance 'fast' two nodes, and advance 'slow' one node */
            while (fast != NULL) { 
                fast = fast->next; 
                if (fast != NULL) { 
                    slow = slow->next; 
                    fast = fast->next; 
                } 
            
            }

            *frontRef = source; 
            *backRef = slow->next; 
            slow->next = NULL; 
        }

        void mergeSort(Node** addHead) { 
            Node* head1 = *addHead; 
            Node* a; 
            Node* b; 
  
            // length is 0 or 1
            if ((head1 == NULL) || (head1->next == NULL)) return; 
  
            // spliting the head in two sublist. */
            frontBackSplit(head1, &a, &b); 
  
            /* Recursively sort the sublists */
            mergeSort(&a); 
            mergeSort(&b); 
  
            /* answer = merge the two sorted lists together */
            *addHead = sortedMerge(a, b); 
        }

    public:
        /* Constructor. */
        SinglyLinkedList(bool isSorted = false) {
            head = NULL;
            this -> isSorted = isSorted;
        }

        /* Getter and setter for isSorted. */
        bool getIsSorted() {
            return isSorted;
        }

        void setIsSorted(bool toSet) {
            if (!isSorted && toSet) {
                // We need to sort the list is if sorted was false in the midway and we want it to be true.
                sort();
            } 

            this -> isSorted = toSet;
        }

        /* Methods to insert data. */
        /** 
         * Will cover the normal insert and insertAtFront.
         * Note that insertInFront will raise exception if we use it with sorted list. 
         */
        void insert(T data) {
            Node* head1 = head;
            Node* newNode = new Node(data);
            
            if (head1) {
                if (isSorted) {
                    if (data < head1 -> data) {
                        newNode -> next = head1;
                        head = newNode;
                    } else {
                        while ((head1-> next) && (head1 -> next -> data < data)) {
                            head1 = head1->next;
                        } newNode -> next = head1 -> next;
                        head1-> next = newNode;
                    }
                } else {
                    while (head1-> next) {
                        head1 = head1->next;
                    } head1 -> next = newNode;
                }
            } else { // What do to if list is empty. 
                // No need to worry about sorted or not as only one node will be there.
                head = newNode;
            }
        }

        void insertAtFront(T data) {
            if (isSorted) {
                throw "Cannot use this method in sorted lists.";
            } else {
                Node* newNode = new Node(data);
                newNode -> next = head;
                head = newNode;
            }
        }

        /* Deletion of the ndoe. */
        /**
         * Will be having methods to remove first occurance if and all the occurances of data.
         * The function that removes first occurance returns a boolean if the data was present(at least once) or not in the list.
         * Definetely, if the data was present at least once, will delete. 
         * Else, we will just return false and list is unchanged if the data was not found.  
         */
        bool deleteOnce(T data) {
            if (head == NULL) return false; // Cannot do anything if list is empty. 
            Node* head1 = head;
            Node* to_delete;

            if (head -> data == data) { // To delete the first element.
                to_delete = head;
                head = head -> next;
                delete to_delete;
                return true;
            }

            while ((head1 -> next) && (head1 -> next -> data != data)) {
                head1 = head1 -> next;
            }

            if (head1 -> next) {
                to_delete = head1 -> next;
                head1 -> next = to_delete -> next;
                delete to_delete;
                return true; 
            } else return false; // Not in the list.
        }
        
        /**
         * Yes, it can be solved with the code while(deleteOnce(data));
         * But it takes alot of iterations. 
         * And multiple there is a more efficient way to do this task in a single iteration. 
         */
        void deleteAll(T data) {
            Node* tempPtr;

            while (head != NULL && head -> data == data) { // Deleting the occourances that come at first.  
                tempPtr = head;             
                head = head -> next;
                delete tempPtr;                
            }

            if (head == NULL) return; // If head becomes NULL, it means the list is now empty.

            Node* head1 = head;

            while(head1 -> next) {
                // Delete all that comes. 
                while (head1 -> next && head1 -> next -> data == data) {
                    tempPtr = head1 -> next;
                    head1 -> next = tempPtr -> next;
                    delete tempPtr;
                } if (head1 -> next == NULL) return;
                head1 = head1 -> next;
            }
        }

        /* Methods to make copy of the list. */
        /**
         * The methods makeCopy and reverseCopy return a new copy. 
         * The copies have isSorted to false. 
         */
        SinglyLinkedList<T> makeCopy() {
            SinglyLinkedList<T> copy;
            Node* head1 = head;
            vector<T> vec;

            while (head1) {
                vec.push_back(head1 -> data);
                head1 = head1 -> next;
            }

            for (int i = vec.size()-1; i > -1; i--) {
                copy.insertAtFront(vec[i]);
            }

            return copy;
        }

        /* Return the reverse copy of the list. */
        /* This list remains unchanged. */
        SinglyLinkedList<T> reverseCopy() {
            SinglyLinkedList<T> reverse;
            Node* head1 = head;

            while (head1) {
                reverse.insertAtFront(head1 -> data);
                head1 = head1 -> next;
            }

            return reverse;
        }

        /* Normal reverse. Reverses this list. */
        /* Cannot use this functionality is a sorted list is there. */
        void reverse(){
            if (isSorted) {
                throw "Cannot use this functionality in a sorted list.";
            } else {
                Node* head1 = head;
                Node *tempPtr1 = NULL, *tempPtr2 = NULL;
 
                while (head1 != NULL) {
                    tempPtr2 = head1 -> next;
                    head1 -> next = tempPtr1;
                    tempPtr1 = head1;
                    head1 = tempPtr2;
                }
                head = tempPtr1;
            }
        }

        /* Sorting algorithm. Normal sort which sorts this list and a function to return sorted copy. */
        void sort() { 
            /*
             * We will be using the merge sort algorithm for this given above in private section. 
             * As the algorithm is recursive and we do not want that our head to get seen, we write this function which calls merge sort for us. 
             * We select merge sort so the complexity becomes O(nlogn). 
             */
            mergeSort(&(this -> head));
        } 

        SinglyLinkedList<T> getSortedCopy() {
            SinglyLinkedList<T> copy = makeCopy();
            copy.sort();
            return copy;
        }   

        /* Method to display the content of the list with outStream. */
        void display(ostream& outStream) {
            Node* head1 = head;

            while (head1) {
                outStream << head1 -> data << " ";
                head1 = head1 -> next;
            } outStream << endl;
        }
};