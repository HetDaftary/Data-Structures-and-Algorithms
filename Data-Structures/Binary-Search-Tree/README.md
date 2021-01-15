# Functionalities implemented:
* <b>Private class Node:</b> Defines how a node of tree should look like.
* <b>insert:</b> To insert the data in array. 
* <b>deleteOnce:</b> Deletes an element from the tree one time as per it's first apperance. Returns a boolean based on if the node was deleted or not. 
* <b>preOrderTraversal:</b> Does pre-Order-Traveral of the BST
* <b>inOrderTraversal:</b> Does in-Order-Traveral of the BST
* <b>postOrderTraversal:</b> Does post-Order-Traveral of the BST
* <b>search:</b> Returns a boolean based on the element was present or not.

# Some important points:
* We here use a recurrsion has it makes things easy to handle with BST using helper function in the private section.
* The helper methods can be called with the methods mentioned above to handle operations of the tree.

# Code Snippets for Examples:

* Make a BST:

        BinarySearchTree<int> t1;
        
* Insert Data in the BST:
        
        t1.insert(i);
        
* Delete a node from the tree:
        
        bool ans = t1.deleteOnce(i);
        
* Search for an element x in the list:
        
        bool ans = t1.search(x);
        
* Do pre-Order-Traversal:
 
        t1.preOrderTraversal(cout); // Default separation. 
        
* Do post-Order-Traversal:
    
        t1.postOrderTraversal(cout);
        
* Do in-Order-Traversal:

        t1.inOrderTraversal(cout);
