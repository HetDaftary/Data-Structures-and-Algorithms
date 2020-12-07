#include <bits/stdc++.h>
using namespace std; 

template<class T> class Node {
    public:
        T data;
        Node* next;
        Node* prev
        Node(T data) {
            this -> data = data;
            this -> next = NULL;
            this -> prev = NULL;
        }
};

template<class T> class DoublyLinkedList {
    private:
        Node<T>* head;
        bool isSortedList;

        void insertInSortedList(Node<T>* head1, Node<T>* newNode) {}

        void insertAtEnd(Node<T>* head1, Node<T>* newNode) {}
    public:
        DoublyLinkedList(bool isl = false) {
            head = NULL;
            isSortedList = isl;
        }

        bool getIsSortedList() {
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
                head1 -> prev = newNode;
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
        DoublyLinkedList<T> makeCopy() {
            vector<T> vec;
            Node<T>* head1 = head;
            DoublyLinkedList<T> copyOfList;
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

        bool deleteNode(T data) {}

        void deleteAllOccurance(T data) {}

        static bool comparatorForNode(Node<T>* n1, Node<T>* n2) {
            return (n1 -> data < n2 -> data);
        }

        void sortList(bool toReverse = false) {}

        DoublyLinkedList<T> returnSortedCopy(bool toReverse = false) {
            DoublyLinkedList<T> copyOfList = makeCopy();
            copyOfList.sortList(toReverse);
            return copyOfList;
        }
};