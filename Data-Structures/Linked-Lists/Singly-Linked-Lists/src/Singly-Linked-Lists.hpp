#include <bits/stdc++.h>
using namespace std; 

template<class T> class Node {
    public:
        T data;
        Node* next;
        Node(T data) {
            this -> data = data;
            this -> next = NULL;
        }
};

template<class T> class SinglyLinkedList {
    private:
        Node<T>* head;
        bool isSortedList;

        /*
         * The functions insertInSortedList and insertAtEnd are private because my intent is to call them from insert has the case maybe.
         * So, the user needs not to worry about calling different functions based on sorted or un sorted list. 
         * The functions insertInSortedList will be called by insert function in public which is used as abstraction.
         * These functions do not handle the case where head1 is NULL has it is handled in insert function. 
         * Insert functions makes the node and a copy of the head and gives that to these functions to reduce on number of lines. 
         */

        /* Used by the insert function used. */
        void insertInSortedList(Node<T>* head1, Node<T>* newNode) { 
            if (head1 -> data > newNode -> data) {
                newNode -> next = head1;
                head = newNode;
            } else {
                while (head1 -> next && head1 -> next -> data < newNode -> data) {
                    head1 = head1 -> next;
                }

                newNode -> next = head1 -> next;
                head1 -> next = newNode;
            }
        }

        /* Used by the insert function used. */
        void insertAtEnd(Node<T>* head1, Node<T>* newNode) {
            while(head1 -> next) {
                head1 = head1 -> next;
            }
        
            head1 -> next = newNode;
        }

    public:
        /* Constructors for the linked list. */
        SinglyLinkedList(bool isl = false) {
            head = NULL;
            isSortedList = isl;
        } 

        /* Getter and Setter for the is sorted list. */
        bool getIsSortedList() {
            /*
             * It does not see if the list is sorted or not. It just sees if the list enforces this rule or not. 
             */
            return isSortedList;
        }

        void setISortedList(bool toSet) {
            /*
             * The idea is, if we try to set unsorted to sorted, we need to sort. 
             * Can change boolean in other cases directly. 
             */ 
            if (!isSortedList && toSet && head != NULL) { // If head is NULL, there is nothing to sort.
                sortList();
            } isSortedList = toSet;
        }

        /* To insert data. */
        void insert(T data) {
            Node<T>* head1 = head;
            Node<T>* newNode = new Node<T>(data);

            if (head1 == NULL) {
                head = newNode;
            } else {
                if (isSortedList) {
                    insertInSortedList(head1, newNode);
                } else {
                    insertAtEnd(head1, newNode);
                }
            }
        }

        void insertAtFront(T data) {
            /*
             * Throws exception if you try to use it in Sorted List.  
             */
            if (isSortedList) {
                throw "You cannot use insertAtFront in the sorted list.";
            } else {
                Node<T>* head1 = head;
                Node<T>* newNode = new Node<T>(data);
                newNode -> next = head1;
                head = newNode;
            }

        } 

        /* Display list. */
        void displayList() {
            Node<T>* head1 = head;

            while (head1) {
                cout << head1 -> data << " ";
                head1 = head1 -> next;
            } cout << endl;
        } 

        /* Make a copy of the linked list. */   
        /* Copy of the list will not get the sorted property. */
        SinglyLinkedList<T> makeCopy() {
            vector<T> vec;
            Node<T>* head1 = head;
            SinglyLinkedList<T> copyOfList;
            /*
             * Has the concept of Singly Linked lists only allow us to move forward. 
             * We firstly get a temp vector to get all the addresses and add them in reverse order with insertAtFront. 
             * This will helps us to get the things done in O(n) time. 
             * If we do not use this method and go on to insert the element one by one with traversing using insert, it takes O(n^2) time.
             */

            while (head1) {
                vec.push_back(head1 -> data);
                head1 = head1 -> next;
            }

            for (int i = vec.size() - 1; i > -1; i--) {
                copyOfList.insertAtFront(vec[i]);
            }

            return copyOfList;
        }

        /* To reverse the link list. */
        SinglyLinkedList<T> reverseList() {
            Node<T>* head1 = head;
            SinglyLinkedList<T> reverseOfList;

            while (head1) {
                reverseOfList.insertAtFront(head1 -> data);
                head1 = head1 -> next;
            }

            return reverseOfList;
        }      

        /* To serach if an element is in the list or not. */
        bool isIn(T data) {
            Node<T>* head1 = head;

            while (head1) {
                if (head1 -> data == data) {
                    return true;
                } head1 = head1 -> next;
            }

            return false;
        }

        /* To delete if an element if it is present. */
        /* Returns a boolean which depends on where element was deleted or not. */
        /* Only deletes the first occurance of the element. */
        bool deleteNode(T data) {
            Node<T>* head1 = head;
            Node<T>* tempPtr;

            if (head1 == NULL) return false;
            // if head is NULL, then you cannot find data, thus cannot delete it. 

            if (head1 -> data == data) { // Head is the node to delete.
                head = head1 -> next;
                delete head1;
                return true;
            }

            while(head1 -> next && (head1 -> next -> data) != data) {
                head1 = head1 -> next;
            }

            if (head1 -> next) {
                tempPtr = head1 -> next;
                head1 -> next = tempPtr -> next;
                delete tempPtr;
                return true;
            } else {
                return false;
            }
        }

        /* Deletes every single occurance of the data in list. */
        void deleteAllOccurance(T data) {
            /*
             * Yes, I know I can use delete node with a while loop here.
             * Like, while(deleteNode(data)); 
             * This will slove the problem but the solution is not that efficient.
             * The time complexivity goes like O(a*n) where a is number of occurances and n is number of elements in the list. 
             * The reason is that if x comes a times, it searchs for the x, a times from the start deletes them and return true. 
             * Then after that, ther is no more occurances of x in the list, thus it returns flase after traversing the list to confirm that fact. 
             * Thus the list is traversed for a + 1 times in total. 
             * We can do better as we know we do not need to start the things from starting everytime. 
             * As, if we found any occurance we would have deleted it without fail. 
             * I am trying get the things done in O(n) time by a single traversal. 
             */

            Node<T>* tempPtr;

            while (head != NULL && head -> data == data) { // Deleting the occourances that come at first.  
                tempPtr = head;             
                head = head -> next;
                delete tempPtr;                
            }

            if (head == NULL) return; // If head becomes NULL, it means the list is now empty.

            Node<T>* head1 = head;

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

        static bool comparatorForNode(Node<T>* n1, Node<T>* n2) {
            return (n1 -> data < n2 -> data);
        }

        void sortList(bool toReverse = false) {
            /*
             * Note that sortList or returnSortedList does not set the boolean of is sorted to true. 
             * If you want to get list with sorting has enforced property, use the setter of sorted list boolean.
             */
            // Sorts this list in the pointer by moving pointers. 
            vector<Node<T>*> vec;
            Node<T>* tail = NULL;

            while (head) {
                vec.push_back(head);
                head = head -> next;
            } // Collecting all the pointers from list to a vector.

            sort(vec.begin(), vec.end(), comparatorForNode);

            if (toReverse) { // Sorts in reverse manner. 
                head = vec[0];
                head -> next = NULL;
                for (int i = 1; i < vec.size(); i++) {
                    vec[i] -> next = head;
                    head = vec[i];
                }
            } else { // Sorts normally. 
                head = vec[0];
                tail = vec[0];
                for (int i = 1; i < vec.size(); i++) {
                    tail -> next = vec[i];
                    tail = tail -> next;
                } tail -> next = NULL;
            }
        }

        SinglyLinkedList<T> returnSortedCopy(bool toReverse = false) {
            SinglyLinkedList<T> copyOfList = makeCopy();
            copyOfList.sortList(toReverse);
            return copyOfList;
        }
};     