#include <iostream>
#include "bst.hpp"

class BinarySearchTree: public SearchTree {
  private:
    Node *root;
    Node *putNode(Node *node, int key, char value);
    Node *getNode(Node *node, int key);
    Node *min(Node *node);
    int size(Node *node);
  public:
    BinarySearchTree() : root(NULL) {
    }
    ~BinarySearchTree() {
    }
    void put(int key, char value);
    char get(int key);
    int size();
    char min();
};

void BinarySearchTree::put(int key, char value) {
  root = putNode(root, key, value);
}

char BinarySearchTree::get(int key) {
  Node *node = getNode(root, key);
  if (node == NULL) {
    throw "No such key";
  }
  return node->value;
}

int BinarySearchTree::size() {
  return size(root);
}

Node * BinarySearchTree::min(Node *node) {
  if (node->left == NULL) {
    return node;
  }
  return min(node->left);
}

char BinarySearchTree::min() {
  return min(root)->value;
}

Node * BinarySearchTree::putNode(Node *node, int key, char value) {
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
  // we have to increment the size of all nodes, not just the node added.
  node->count = size(node->left) + size(node->right) + 1;
  return node;
}

Node * BinarySearchTree::getNode(Node *node, int key) {
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
int BinarySearchTree::size(Node *node) {
  return node == NULL ? 0 : node->count;
}

