#if defined(_WIN32) || defined(_WIN64) || (defined(__CYGWIN__) && !defined(_WIN32)) // Windows uses a different system for path names. 
    #include "..\includer.hpp"
#else 
    #include "../includer.hpp"
#endif

int main() {
    BinarySearchTree<int> t1;

    for (int i = 0; i < 10; i++) {
        t1.insert(i);
    }

    t1.preOrderTraversal(cout);
    t1.postOrderTraversal(cout);
    t1.inOrderTraversal(cout);

    cout << t1.search(5) << " " << t1.search(11) << endl;

    cout << t1.deleteOnce(4) << " " << t1.deleteOnce(11) << endl;

    t1.preOrderTraversal(cout);
    t1.postOrderTraversal(cout);
    t1.inOrderTraversal(cout);

    return 0;
}