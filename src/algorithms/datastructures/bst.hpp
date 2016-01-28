#ifndef SEARCH_TREE_H
#define SEARCH_TREE_H

class Node {
  friend class BinarySearchTree;
  private:
    Node *left;
    Node *right;
    int key;
    char value;
    int count;
  public:
    Node(int key, char value) : Node(key, value, NULL, NULL, 1) {} ;
    Node(int key, char value, Node *left, Node *right, int count) {
      this->key = key;
      this->value = value;
      this->left = left;
      this->right = right;
      this->count = count;
    }
};

class SearchTree {
  public:
    void put(int key, char value);
    char get(int key);
    int size();
    char min();
    char max();
    /* return the largest key less than, or equal to the passed-in key */
    int floor(int key);
    int ceil(int key);
};
#endif
