#include <iostream>

class Node {
  friend class BinarySearchTree;
  private:
    Node *left;
    Node *right;
    int key;
    char value;
  public:
    Node(int key, char value) : Node(key, value, NULL, NULL) {} ;
    Node(int key, char value, Node *left, Node *right) { 
      this->key = key;
      this->value = value;
      this->left = left;
      this->right = right;
    }
};

class BinarySearchTree {
  private:
    Node *root;
  public:
    BinarySearchTree() : root(NULL) {
    }
    ~BinarySearchTree() {
    }
    void put(int key, char value) {
      if (root == NULL) {
        root = new Node(key, value);
      }
    }
    char get(int key) {
      if (root == NULL) {
        throw "No such key";
      }
      return '0';
    }
};
