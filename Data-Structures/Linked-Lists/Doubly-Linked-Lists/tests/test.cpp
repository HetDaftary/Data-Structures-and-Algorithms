#include "../src/Doubly-Linked-Lists.hpp"

int main() {
    DoublyLinkedList<int> list1;

    for (int i = 0; i < 10; i++) {
        list1.insert(i);
    }

    list1.insertAtFront(10);

    // cout << list1.isIn(6) << " " << list1.isIn(15) << endl;
    list1.displayList();

    DoublyLinkedList<int> list2(true);
    
    list2.insert(5);
    list2.insert(3);
    list2.insert(4);

    // list2.insertAtFront(6);
    // Should throw an exception here. 
    // Works. Uncomment this line to see exception thrown.

    list2.displayList();

    DoublyLinkedList<int> copy = list1.makeCopy();
    copy.displayList();

    DoublyLinkedList<int> reverse = list1.reverseList();
    reverse.displayList();

    cout << list2.isIn(4) << " " << list2.isIn(10) << endl;    

    cout << list2.deleteNode(5) << " " << list2.deleteNode(10) << endl;
    list2.displayList();

    DoublyLinkedList<int> list3;

    for(int i = 0; i < 5; i++) {
        list3.insertAtFront(3);
    }

    list3.insertAtFront(4);

    for(int i = 0; i < 5; i++) {
        list3.insertAtFront(3);
    }

    list3.insertAtFront(4);

    for(int i = 0; i < 5; i++) {
        list3.insertAtFront(3);
    }

    list3.displayList();

    list3.deleteAllOccurance(3);
    list3.displayList();

    list1.setISortedList(true);
    list1.displayList();

    DoublyLinkedList<int> sortedCopy = copy.returnSortedCopy();
    DoublyLinkedList<int> sortedCopy1 = copy.returnSortedCopy(true);
    copy.displayList();
    sortedCopy.displayList();
    sortedCopy1.displayList();
    return 0;
}
