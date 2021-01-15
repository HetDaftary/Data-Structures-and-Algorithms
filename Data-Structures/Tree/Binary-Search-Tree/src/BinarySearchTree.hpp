#include <iostream>
#include <fstream>
using namespace std;

template<class T> class BinarySearchTree {
    private:
        class Node {
            public:
                T data;
                Node *left, *right;

                Node(T key) {
                    this -> data = key;
                    this -> left = NULL;
                    this -> right = NULL;
                }
        };

        Node* root;
        // Other private methods.

        // Helper for insert.
        Node* insertHelper(Node* newNode, Node* root) {
            if (root == NULL) return newNode;

            if (newNode -> data < root -> data) root -> left = insertHelper(newNode, root -> left);
            else root -> right = insertHelper(newNode, root -> right);
            return root;
        } 

        // Helper for search.
        bool searchHelper(Node* root, T key) { 
            if (root == NULL || root -> data == key) { 
                if (root) return true;
                return false;
            }
     
            if (root -> data <= key) {
                return searchHelper(root->right, key);
            } 
  
            return searchHelper(root->left, key); 
        }

        // Helper for delete.
        Node* deleteHelper(Node* root, T key, bool* ans) {
            if (root == NULL) {
                return root;
            }
 
            if (key < root->data) {
                root->left = deleteHelper(root->left, key, ans);
            }
 
            else if (key > root->data) {
                root->right = deleteHelper(root->right, key, ans);
            }
 
            else {
                if (root->left == NULL) {
                    Node* temp = root->right;
                    delete root;
                    *ans = true;
                    return temp;
                }
                else if (root->right == NULL) {
                    Node* temp = root->left;
                    delete root;
                    *ans = true;
                    return temp;
                }
 
                Node* temp1 = root -> right;

                while (temp1 && temp1->left != NULL) {
                    temp1 = temp1->left;
                }

                root->data = temp1->data;
                root->right = deleteHelper(root->right, temp1->data, ans);
            }
            return root;
        }

        // Helper methods for traversal.
        void preOTHelper(ostream& outStream, string sep, Node* ptr) {
            if (ptr) {
                outStream << ptr -> data << sep;
                preOTHelper(outStream, sep, ptr -> left);
                preOTHelper(outStream, sep, ptr -> right);
            }
        }

        void postOTHelper(ostream& outStream, string sep, Node* ptr) {
            if (ptr) {
                preOTHelper(outStream, sep, ptr -> left);
                preOTHelper(outStream, sep, ptr -> right);
                outStream << ptr -> data << sep;
            }
        }

        void inOTHelper(ostream& outStream, string sep, Node* ptr) {
            if (ptr) {
                preOTHelper(outStream, sep, ptr -> left);
                outStream << ptr -> data << sep;
                preOTHelper(outStream, sep, ptr -> right);
            }
        }
    public:
        // Constructor.
        BinarySearchTree() {
            this -> root = NULL;
        }
 
        // To insert a key in the tree.
        void insert(T key) {
            Node* newNode = new Node(key);

            this -> root = insertHelper(newNode, this -> root);
        }

        // To delete a given key from the tree.
        bool deleteOnce(T key) {
            bool ans = false;
            this -> root = deleteHelper(this -> root, key, &ans);
            return ans;
        }

        // To search for a key in the tree.
        bool search(T key) {
            return searchHelper(this -> root, key);
        }

        // Traversal methods. 
        /**
         * Here, we use the recurrsive helper function in the private section and call it.
         */
        void preOrderTraversal(ostream& outStream, string sep = " ") {
            preOTHelper(outStream, sep, this -> root);
            outStream << endl;
        }

        void postOrderTraversal(ostream& outStream, string sep = " ") {
            postOTHelper(outStream, sep, this -> root);
            outStream << endl;
        }

        void inOrderTraversal(ostream& outStream, string sep = " ") {
            inOTHelper(outStream, sep, this -> root);
            outStream << endl;
        }
};