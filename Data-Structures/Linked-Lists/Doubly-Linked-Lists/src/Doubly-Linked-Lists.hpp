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
};