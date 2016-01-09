#include <iostream>

class IntNode {
  friend class DLinkedList;
  private:
    int value;
    IntNode *next;
    IntNode *previous;
  public:
    IntNode(int value, IntNode *next, IntNode *previous = NULL) {
      this->value = value;
      this->next = next;
      this->previous = previous;
    }
    ~IntNode() {
    }
};

class DLinkedList {
  private: 
    IntNode *head;
    IntNode *tail;
    int length;
  public:
    DLinkedList() : head(NULL), tail(NULL), length(0) {
    }

    bool empty() const {
      return head == NULL;
    }

    DLinkedList &addFront(int value) {
      IntNode *newNode = new IntNode(value, NULL);
      if (empty()) {
        head = newNode;
      } else {
        IntNode *current = head;
        newNode->next = current;
        current->previous = newNode;
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
      if (empty()) {
        return -1;
      }
      return head->next->value;
    }

    int end() const {
      if (empty()) {
        return -1;
      }
      return tail->value;
    }

    DLinkedList &addEnd(int value) {
      IntNode *newNode = new IntNode(value, NULL);
      if (empty()) {
        addFront(value);
      } else {
        IntNode *current = tail;
        current->next = newNode;
        newNode->next = NULL;
        newNode->previous = current;
        tail = newNode;
      }
      length++;
      return *this;
    }

    int removeEnd() {
      if (empty()) {
        return -1;
      }
      IntNode *old = tail;
      int value = old->value;
      old->previous = NULL;
      delete old;
      length--;
      return value;
    }

    int size() const {
      return length;
    }

    bool contains(int nr) const {
      if (empty()) {
        return false;
      }
      IntNode *p = tail;
      do {
        if (p->value == nr) {
          return true;
        }
      } while (p->previous != NULL);
      return false;
    }

    const DLinkedList &print() const {
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

