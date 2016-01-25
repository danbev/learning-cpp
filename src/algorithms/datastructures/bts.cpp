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
    Node * putNode(Node *node, int key, char value) {
      if (node == NULL) {
          return new Node(key, value);
      }
      if (key < node->key) {
        node->left = putNode(node->left, key, value);
      } else if (key > node->key) {
        node->right = putNode(node->right, key, value);
      } else {
        node->value = value;
      }
      return node;
    }
    Node * getNode(Node *node, int key) {
      if (node == NULL) {
        return NULL;
      }
      if (key < node->key) {
        return getNode(node->left, key);
      } else if (key > node->key) {
        return getNode(node->right, key);
      } else {
        return node;
      }
    }
  public:
    BinarySearchTree() : root(NULL) {
    }
    ~BinarySearchTree() {
    }

    void put(int key, char value) {
      root = putNode(root, key, value);
    }

    char get(int key) {
      Node *node = getNode(root, key);
      if (node == NULL) {
        throw "No such key";
      }
      return node->value;
    }
};
