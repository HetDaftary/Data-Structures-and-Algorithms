#include <iostream>
#include <fstream> // For getting the out interface from the user.
using namespace std;
// DoublyLinkedLists have a pointer to back and pointer to tail so we do not vectors.

template<class T> class DoublyLinkedList {
    private:
        /* Node class to be used. */
        class Node {
            public:
                T data;
                Node* prev;
                Node* next;

            Node(T d) {
                data = d;
                prev = NULL;
                next = NULL;
            }
        };

        /* My data of the list. */
        Node* head;
        Node* tail;
        bool isSorted;

        /* Private methods that can help public methods go here. */

        /* Default compare function. */
        static int compare_function(T a, T b) {
            if (a > b) return 1;
            if (a == b) return 0;
            return -1;
        } 

        /* Methods for the sort algorithm. */
        Node *split(Node *head) {  
            Node *fast = head,*slow = head;  
            while (fast->next && fast->next->next) {  
                fast = fast->next->next;  
                slow = slow->next;  
            }  
            Node *temp = slow->next;  
            slow->next = NULL;  
            return temp;  
        }  

        Node* merge(Node *first, Node *second, int (*compare)(T a, T b)) {
            if (!first) return second;  
  
            if (!second) return first;  
  
            if (compare(first->data, second->data) == -1) {  
                first->next = merge(first->next,second, compare);  
                first->next->prev = first;  
                first->prev = NULL;  
                return first;  
            } else {  
                second->next = merge(first,second->next, compare);  
                second->next->prev = second;  
                second->prev = NULL;  
                return second;  
            }  
        } 

        Node *mergeSort(Node *head, int (*compare)(T a, T b)) {  
            if (!head || !head->next) return head;  
            Node *second = split(head);  
  
            head = mergeSort(head, compare);  
            second = mergeSort(second, compare); 
            return merge(head, second, compare);  
        }  

    public:
        /* Constructor. */
        DoublyLinkedList(bool isSorted = false) {
            this -> head = NULL;
            this -> isSorted = isSorted;
        }

        /* Getter and setter for isSorted. */
        bool getIsSorted() {
            return isSorted;
        }

        void setIsSorted(bool toSet) {
            if (!isSorted && toSet) {
                // We need to sort the list is if sorted was fals_heade in the midway and we want it to be true.
                sort(compare_function);
            } 

            this -> isSorted = toSet;
        }

        /* Methods to insert data. */
        /** 
         * Will cover the normal insert and insertAtFront.
         * Note that insertInFront will raise exception if we use it with sorted list. 
         */
        void insert(T data) {
            Node* newNode = new Node(data);
            Node* head1 = this -> head; 
            if (head1) {
                if ((this -> isSorted) && (this -> tail -> data < data)) {
                    /**
                     * Sorted list means tails_head is the largest element.
                     * Thus, if the data is larger that the tail data, we can directly insert at last.
                     * Thus, it does not waste n iterations in that case.
                     */
                    if (this -> head -> data < data) {
                        head1 -> prev = newNode;
                        newNode -> next = head1;
                        this -> head = newNode;
                        return;
                    }

                    while((head1 -> next) && (head1 -> next -> data < data)) {
                        head1 = head1 -> next;
                    }

                    newNode -> prev = head1;
                    newNode -> next = head1 -> next;
                    head1 -> next -> prev = newNode;
                    head1 -> next = newNode;
                } else {
                    // No need to traverse as 
                    newNode -> prev = this -> tail;
                    this -> tail -> next = newNode;
                    this-> tail = newNode;
                }   
            } else {
                // Nothing to do if the list is already sorted. 
                this -> tail = newNode;
                this -> head = newNode;
            }
        }

        void insertAtFront(T data) {
            if (isSorted) throw "Cannot use this method in sorted lists.";
            
            Node* newNode = new Node(data);

            if (this -> head) {
                newNode -> next = this -> head;
                this -> head -> prev = newNode;
                this -> head = newNode;                
            } else {
                this -> head = newNode;
                this -> tail = newNode;
            }
        }
        
        /**
         * Serach function.
         * Returns boolean on the bases if data is there in the list or not.  
         */
        bool serach(T data) {
            Node* head1 = head;

            while(head1) {
                if (head1 -> data == data) return true;                
                head1 = head1->next;
            } return false;
        }

        /* Deletion of the ndoe. */
        /**
         * Will be having methods to remove first occurance if and all the occurances of data.
         * The function that removes first occurance returns a boolean if the data was present(at least once) or not in the list.
         * Definetely, if the data was present at least once, will delete. 
         * Els_heade, we will just return fals_heade and list is unchanged if the data was not found.  
         */
        bool deleteOnce(T data) {
            Node* head1 = this -> head;
            Node* to_delete;

            if (head1 == NULL) return false;

            if (head1 == this -> tail && head1 -> data == data) {
                // Only one element in the list and need to delete it. 
                delete head1;
                this -> head = NULL;
                this -> tail = NULL;
                return true;
            } 

            // Things are bit simplar as doubly linked list have pointers for prev and next.
            while (head1 && head1 -> data != data) {
                head1 = head1->next;
            }

            if (head1) {
                // Was able to find the element which needs to be deleted.
                to_delete = head1;
                to_delete -> prev -> next = to_delete -> next;
                to_delete -> next -> prev = to_delete -> prev;
                delete to_delete;
                return true;
            } else return false;
            // Element was not there so not deleted. 
        }

        /**
         * Yes, it can be solved with the code while(deleteOnce(data));
         * But it takes alot of iterations. 
         * And multiple there is a more efficient way to do this task in a single iteration. 
         */
        void deleteAll(T data) {
            Node* head1 = this -> head;
            Node* to_delete;

            while (head1) {
                if (head1 -> data == data) {
                    to_delete = head1;

                    if (to_delete == this -> head) this -> head = this -> head -> next;
                    if (to_delete -> next) to_delete->next->prev = to_delete->prev;
                    if (to_delete -> prev) to_delete->prev->next = to_delete->next;
                    
                    delete to_delete;
                } else head1 = head1 -> next;
            }
        }

        /* Methods to make copy of the list. */
        /**
         * The methods makeCopy and reverseCopy return a new copy. 
         * The copies have isSorted to fals_heade. 
         */
        DoublyLinkedList<T> makeCopy() {
            DoublyLinkedList<T> copy;
            Node* tail1 = this -> tail;

            while(tail1) {
                copy.insertAtFront(tail1 -> data);
                tail1 = tail1->prev;
            } return copy;
        }

        /* Return the reverse copy of the list. */
        /* This list remains unchanged. */
        DoublyLinkedList<T> reverseCopy() {
            DoublyLinkedList<T> copy;
            Node* head1 = this -> head;

            while (head1) {
                copy.insertAtFront(head1 -> data);
                head1 = head1->next;
            } return copy;
        }

        /* Normal reverse. Reverses this list. */
        /* Cannot use this functionality is a sorted list is there. */
        void reverse() {
            if (isSorted) {
                throw "Cannot use this method in sorted lists.";
            } else {
                // We here make a new list and insert the elements in that list. 
                Node* ls_head; 
                Node* ls_tail;
                Node* cur;
                Node* head1 = this -> head;

                if (head1 == NULL || head1 == this -> tail) return;

                ls_head = head1;
                head1 = head1->next;
                ls_head -> next = NULL;
                ls_head -> prev = NULL;
                ls_tail = ls_head;

                while(head1) {
                    cur = head1;
                    head1 = head1->next;
                    cur -> prev = NULL;
                    ls_head -> prev = cur;
                    cur -> next = ls_head;
                    ls_head = cur;
                }
                this -> head = ls_head;
                this -> tail = ls_tail;
            }
        }

        /* Sorting algorithm. Normal sort which sorts this list and a function to return sorted copy. */
        void sort(int (*compare)(T a, T b)) {
            if (isSorted) return;

            this -> head = mergeSort(this -> head, compare);
            Node* head1 = this -> head;

            if (head1) {
                while (head1 -> next) {
                    head1 = head1 -> next;
                } this -> tail = head1;
            }
        }

        DoublyLinkedList<T> getSortedCopy(int (*compare)(T a, T b)) {
            DoublyLinkedList<T> copy = makeCopy();
            copy.sort(compare);
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