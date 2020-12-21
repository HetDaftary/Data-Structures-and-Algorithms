#include <iostream>
#include <vector> 
using namespace std;

template<class T> class SinglyLinkedList {
    private:
        /* The Node class we should use for making the node. */
        class Node {
            private:
                T data;
                Node* next;
            public:
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

        /* The private methods go here. */
    public:
};