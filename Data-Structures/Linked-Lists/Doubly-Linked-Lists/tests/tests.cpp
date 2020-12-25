 #if defined(_WIN32) || defined(_WIN64) || (defined(__CYGWIN__) && !defined(_WIN32)) // Windows uses a different system for path names. 
    #include "..\includer.hpp"
#else 
    #include "../includer.hpp"
#endif

int main() {
    DoublyLinkedList<int> ls;
    
    for (int i = 0; i < 5; i++) {
        ls.insertAtFront(i);
    } 
    
    ls.reverse();
    ls.display(cout);

    for (int i = 0; i < 5; i++) {
        ls.insertAtFront(i);
    } ls.display(cout);

    DoublyLinkedList<int> ls1(true);
    for (int i = 0; i < 5; i++) {
        ls1.insert(i);
    } ls1.display(cout);

    // ls1.reverse();
    // ls1.insertAtFront(10);
    // These lines throw exception and so commented for now. 
    // Can uncomment to see the thrown exception and use exception handling or see the exceptions. 

    cout << ls.deleteOnce(3) << " " << ls.deleteOnce(10) << endl;
    ls.display(cout);

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

    list3.display(cout);

    list3.deleteAll(3);
    list3.display(cout);

    DoublyLinkedList<int> ls3; 
    for (int i = 0; i < 5; i++) {
        ls3.insertAtFront(i);
    } cout << "before sorting: ";
    ls3.display(cout);
    ls3.setIsSorted(true);
    cout << "after sorting: ";
    ls3.display(cout);

    return 0;
}