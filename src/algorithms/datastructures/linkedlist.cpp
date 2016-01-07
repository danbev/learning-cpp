#include <iostream>

class IntNode {
  friend class LinkedList;
  private:
    int value;
    IntNode *next;
  public:
    IntNode(int value, IntNode * next) {
      this->value = value;
      this->next = next;
    }
    ~IntNode() {
    }
};

class LinkedList {
  private: 
    IntNode * head;
    int length;
  public:
    LinkedList() : head(NULL), length(0) {
    }

    bool empty() const {
      return head == NULL;
    }

    LinkedList &addFront(int value) {
      IntNode *newNode = new IntNode(value, NULL);
      if (head == NULL) {
        head = newNode;
      } else {
        IntNode *current = head;
        newNode->next = current;
        head = newNode;
      }
      length++;
      return *this;
    }

    int removeFront() {
      if (head == NULL) {
        return -1;
      }
      IntNode *old = head;
      head = old->next;
      int value = old->value;
      delete old;
      length--;
      return value;
    }

    int front() const {
      if (head == NULL) {
        return -1;
      }
      return head->next->value;
    }

    int size() const {
      return length;
    }

    const LinkedList &print() const {
      if (head == NULL) {
        std::cout << "[empty]" << std::endl;
      } else {
        IntNode * node = head;
        std::cout << "[" << node->value;
        while(node->next) {
          node = node->next;
          std::cout << ", " << node->value;
        }
        std::cout << "]" << std::endl;
      }
      return *this;
    }
};

/*
 * Reverses the passed in array using the LinkedIntList
 */ 
void reverseArray(int arr[], int size) {
  LinkedList list;
  for (int i = 0; i < size; i++) {
    list.addFront(arr[i]);
  }
  for (int i = 0; i < size; i++) {
    arr[i] = list.removeFront();
  }
}

