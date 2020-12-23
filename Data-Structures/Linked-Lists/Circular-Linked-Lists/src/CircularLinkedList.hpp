#include <iostream>
#include <fstream>
#include <vector> // To make the copy. 
using namespace std;

template<class T> class CircularLinkedList {
    private:
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
                    this -> next = NULL;
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
        CircularLinkedList(bool isSorted = false) {
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
                        // Element to be inserted needs to be inerted at front of the list.
                        newNode -> next = head1;

                        while (head1 -> next != this -> head) {
                            head1 = head1 -> next;
                        }

                        head1 -> next = newNode;
                        this -> head = newNode;
                    } else {
                        while ((head1 -> next != this -> head) && (head1 -> next -> data < data)) {
                            head1 = head1 -> next;
                        } newNode -> next = head1 -> next;
                        head1 -> next = newNode;
                    }
                } else {
                    while (head1 -> next != this -> head) {
                        head1 = head1 -> next;
                    } 
                    newNode -> next = this -> head;
                    head1 -> next = newNode;
                }
            } else {
                // No need to worry about sorted or not as only one node will be there.
                this -> head = newNode;
                newNode -> next = newNode;
            }
        }

        void insertAtFront(T data) {
            if (isSorted) {
                throw "Cannot use this method in sorted lists.";
            } else {
                Node* newNode = new Node(data);
                newNode -> next = head;
                Node* head1 = this -> head;

                if (this -> head == NULL) {
                    newNode -> next = newNode;
                    this -> head = newNode;
                    return;
                }

                while (head1 -> next != this -> head) {
                    head1 = head1 -> next;
                } head1 -> next = newNode;

                this -> head = newNode;
            }
        }

        /**
         * Serach function.
         * Returns boolean on the bases if data is there in the list or not.  
         */
        bool serach(T data) {
            Node* head1 = head;

            while(head1 -> next != this -> head) {
                if (head1 -> data == data) return true;                
                head1 = head1->next;
            } return false;
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

            if ((head1 -> next == this -> head) && (head1 -> data == data)) {
                // Only one element in the list and need to delete it. 
                delete head1;
                this -> head = NULL;
                return true;
            }

            if (head1 -> data == data) {
                // To delete first node in list with multiple elements. 
                to_delete = this -> head;

                while (head1 -> next != this -> head) {
                    head1 = head1->next;
                } head1 -> next = to_delete -> next;
                this -> head = this -> head -> next;
                delete to_delete;
                return true;
            } 

            while ((head1 -> next != this -> head) && (head1 -> next -> data != data)) {
                head1 = head1->next;
            } to_delete = head1->next;
            if (head1 -> next == this -> head) {
                return false;
                // Element not found.
            } else {
                head1 -> next = to_delete -> next;
                delete to_delete;
                return true;
            }
        }

        /**
         * Yes, it can be solved with the code while(deleteOnce(data));
         * But it takes alot of iterations. 
         * And multiple there is a more efficient way to do this task in single iteration. 
         */
        void deleteAll(T data) {
            if (this -> head == NULL) {
                return;
            } else {
                Node* head1 = this -> head;
                Node* prev = this -> head;
                bool run = true;

                while (run) {
                    if (head1->data == data) {
                        if (head1 == this -> head) {
                            if (this -> head == this -> head->next) { 
                                this -> head = NULL;
                                break;
                            } else { 
                                this -> head = this -> head->next;
                                head1 = this -> head->next;
                                prev = this -> head;
                            }
                        } else {
                            prev->next = head1->next;
                            head1 = head1->next;
                        }
                    } else { 
                        prev = head1;
                        head1 = head1->next;
                        if (head1 == this -> head) run = false;
                    }
                }
            }
        }

        /* Methods to make copy of the list. */
        /**
         * The methods makeCopy and reverseCopy return a new copy. 
         * The copies have isSorted to false. 
         */
        CircularLinkedList<T> makeCopy() {
            CircularLinkedList<T> copy;
            Node* head1 = this -> head;
            vector<T> vec;

            while (head1 -> next != this->head) {
                vec.push_back(head1 -> data);
                head1 = head1 -> next;
            }

            for (int i = vec.size()-1; i > -1; i--) {
                copy.insertAtFront(vec[i]);
            }

            return copy;
        }

        CircularLinkedList<T> reverseCopy() {
            CircularLinkedList<T> copy = makeCopy();
            /* Has, the new list is not enforcing sorting, it can use reverse function. */
            copy.reverse(); // Because, I want to do my task in O(n) time. 
            return copy;
        }

        void reverse() {
            if (isSorted) {
                throw "Cannot use this functionality in a sorted list.";
            } else {
                Node* head1 = this -> head;
                Node *prev = NULL, *nextPtr = NULL;

                do {
                    nextPtr = head1 -> next;
                    head1 -> next = prev;
                    prev = head1;
                    head1 = nextPtr;
                } while(head1 != this -> head);
                
                this -> head -> next = prev;
                this -> head = prev;
            }
        }

        /* Sorting algorithm. Normal sort which sorts this list and a function to return sorted copy. */
        void sort() { 
            /*
             * We will be using the merge sort algorithm for this given above in private section. 
             * As the algorithm is recursive and we do not want that our head to get seen, we write this function which calls merge sort for us. 
             * We select merge sort so the complexity becomes O(nlogn). 
             */

            if (this -> head == NULL || this -> head -> next == this -> head) return;

            Node* head1 = this -> head;
            while (head1 -> next != this -> head) {
                head1 = head1 -> next;
            } head1 -> next = NULL;

            mergeSort(&(this -> head));

            while (head1 -> next != NULL) {
                head1 = head1 -> next;
            } head1 -> next = this -> head;
        } 

        CircularLinkedList<T> getSortedCopy() {
            DoublyLinkedList<T> copy = makeCopy();
            copy.sort();
            return copy;
        }
    
        /* Method to display the content of the list with outStream. */
        void display(ostream& outStream) {
            Node* head1 = this -> head;
            // This head = NULL will cause exception. 

            if (head1 == NULL) return;

            do {
                outStream << head1 -> data << " ";
                head1 = head1 -> next;
            } while(head1 != this -> head);
            outStream << endl;
        }
};
