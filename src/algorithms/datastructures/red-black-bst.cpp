#include <stdio.h>

/*
 * Background:
 * To work around the issue with Binary Search Trees(BST) where we cannot
 * guarantee the insertion order of keys. Depending on the order the
 * keys get inserted, the worst case performance of BST could be N for
 * both inserts and searches.
 *
 * We want the worst-case performace to be logarithmic (as is the
 * case for BST in it best/average case) no matter the sequence of 
 * keys used to construct it. We want the tree to be balanced.
 *
 * We can accomplish this by introducing a 2-3 search tree which is a tree
 * where in addition to the normal 2-nodes in a BST, we also have 3-nodes.
 *
 * A 2-node is a node that has two links and one value.
 * A 3-node is a node that has three links and two values.
 *
 * [2-node]       (G)
 *               /    \
 * [3-node]    (C  E)  (K)
 *            /  |  \     \ [null link]
 *          (A) (D)  (F)
 *
 * A perfectly balanced 2-3 search tree is where all null links are the same
 * distance from the root.
 * The only time that the height of the tree increases is when the root node
 * is split. In every other case the height remains the same.
 *
 * To implement a 2-3 tree the number of transformations and a substantial
 * amount of code is required to implement it, making the algorithm slower 
 * than standard BST search and insert which is not what we had in mind.
 * 
 * Left leaning Red-black BST
 * The idea is to encode 2-3 trees by using a standard BST as the starting point.
 * We need to add extra information for the 3 nodes.
 * We have two different types of links, Red links and Black links:
 *
 * 1. Red links
 * Binds two 2-nodes to represent a 3-node. So a 3-node (three links and two values) 
 * is represented by two 2-nodes connected by a single red link that "leans" left.
 *              (C  E)                        (E)                 
 *             /   |  \            [Red link]/   \ [Black link]
 *[less than C][between][greater than E]  (C)      [greater than E]
 *                                       /   \
 *                            [less than C]  [between C and E]
 *
 * How is this any different from a normal BST then? The height is the same for a
 * normal BST and the above Red-black BST is it not?
 * Well it is, but this where the red/black links come into play. The tree has perfect 
 * balance meaning that every path from the root to a null link has the same number 
 * of black links (called the tree's black height)
 * If you think about the number compares for a 3-node, you still have the same number
 * of compares for both. For the 2-3 tree if we search for D then we have to compare if
 * D is greater than C, and if it is less than E. For the RedBlackBST we follow the links
 * starting with a compare against E, but D is less so we go left and then compare to C 
 * which will lead us right. But still two compares.
 * 
 * For a 3-node the larger of the two keys will become the parent of the "sub" bst. The link 
 * will be red to tell them apart from the other black links.
 *
 * 2. Black links
 * Bind together the 2-3 tree.
 *
 * Properties of a RedBlack BST:
 * - Red links lean left
 * - No node has two red links connected to it
 * - The tree has perfect balance meaning that every path from the root to a null link
 *   has the same number of black links (called the tree's black height)
 *
 * Let's take the worst case senario from a normal BinarySearchTree where we insert keys
 * in acending order:
 *                              rotate                flip
 *  (A)                     (A)          (B)     (B)          (B)          (B)         (B)
 *     \                      \ [R]  [R] /  [R] /   \ [R]     / \          / \     [R] /  \
 *      (B)                    (B)     (A)    (A)   (C)     (A)  (C)     (A)  (C)   (A)   (D)
 *        \                                                                     \ [R] [R] /
 *         (C)                                                                  (D)    (C)
 *           \
 *            (D)
 */
class Node {
    friend class RedBlackBST;
    int key;
    char value;
    Node* left;
    Node* right;
    // color of the link from the parent node.
    bool red;
    int count;
    public: 
        Node(int key, int value) : Node(key, value, NULL, NULL, false, 0) {};
        Node(int key, int value, bool red, int count) : Node(key, value, NULL, NULL, red, count) {};
        Node(int key, char value, Node *left, Node *right, bool red = false, int count = 0) {
            this->key = key;
            this->value = value;
            this->left = left;
            this->right = right;
            this->red = red;
            this->count = count;
        }
};

class RedBlackBST {
    private:
        Node *root;
        Node *putNode(Node *node, int key, char value);
        Node *getNode(Node *node, int key);
        Node *min(Node *node);
        Node *max(Node *node);
        int size(Node *node);
        int rank(const Node *node, int key);
        bool isRed(Node* node);
        bool hasTwoRedLeftLinks(Node* node);
        Node* rotateLeft(Node* node);
        Node* rotateRight(Node* node);
        void flipColors(Node* node);
    public:
        RedBlackBST() : root(NULL) {}
        ~RedBlackBST() {}
        void put(int key, char value);
        char get(int key);
        int size();
        char min();
        char max();
        int rank(int key);
};

void RedBlackBST::put(int key, char value) {
    root = putNode(root, key, value);
}

Node * RedBlackBST::putNode(Node *node, int key, char value) {
    if (node == NULL) {
        return new Node(key, value, true, 1);
    }
    if (key < node->key) {
        node->left = putNode(node->left, key, value);
    } else if (key > node->key) {
        node->right = putNode(node->right, key, value);
    } else {
        node->value = value;
    }

    if (isRed(node->right) && !isRed(node->left)) {
        node = rotateLeft(node);
    }
    if (isRed(node->left) && isRed(node->left->left)) {
        node = rotateRight(node);
    }
    if (hasTwoRedLeftLinks(node)) {
        flipColors(node);
    }
    node->count = size(node->left) + size(node->right) + 1;
    return node;
}

bool RedBlackBST::isRed(Node* node) {
    return node == NULL ? false :node->red;
}

bool RedBlackBST::hasTwoRedLeftLinks(Node* node) {
    if (node->left == NULL) {
        return false;
    }
    if (node->left->left == NULL) {
        return false;
    }
    return isRed(node->left) && isRed(node->left->left);
}

void RedBlackBST::flipColors(Node *node) {
    node->red = true;
    node->left->red = false;
    node->right->red = false;
}

// To fix the situation when we have a right leaning red link we rotate the node (n) left. 
//     (b)
//    /   \ red link
//         (c)
//        /   \
// [between b-c][greater than c]
//
// Rotate left:
//     (c)
// red/   \
//  (b)  [greater than c]
// /   \
//     [between b-c]
//
// We are switching from having the smaller of the two keys (b) to having the larger of
// the two keys (c) at the root.
//
Node * RedBlackBST::rotateLeft(Node *parent) {
    Node *newParent = parent->right; 
    parent->right = newParent->left; 
    newParent->left = parent;
    newParent->red = parent->red; // set the color to whatever the parent was
    parent->red = true; 
    newParent->count = parent->count;
    parent->count = 1 + size(parent->left) + size(parent->right);
    return newParent;
}
//
//     (c)
// red/   \
//  (b)  [greater than c]
// /   \
//     [between b-c]
//
// Rotate right:
//     (b)
//    /   \ red link
//         (c)
//        /   \
// [between b-c][greater than c]
//
Node * RedBlackBST::rotateRight(Node *parent) {
    Node *newParent = parent->left; 
    parent->left = newParent->right; 
    newParent->right = parent;
    newParent->red = parent->red;
    parent->red = true;
    newParent->count = parent->count;
    parent->count = 1 + size(parent->left) + size(parent->right);
    return newParent;
}

/*
*  Return the number of keys that are less than the passed-in key
*/
int RedBlackBST::rank(const Node *node, int key) {
    if (node == NULL) {
        return 0;
    }
    if (key == node->key) {
        // return the count of the left. This is not the same as the current nodes count
        // as it also contains the count for its right tree.
        return size(node->left);
    }
    if (key < node->key) {
        // process the left subtree
        return rank(node->left, key);
    }
    // so the key was greater then the current nodes key. 
    // Take the size of the left subtree, plus 1 for this node and 
    // the rank of processing the right subtree.
    return 1 + size(node->left) + rank(node->right, key);
}

int RedBlackBST::rank(int key) {
    return rank(root, key);
}

char RedBlackBST::get(int key) {
    Node *node = getNode(root, key);
    if (node == NULL) {
        throw "No such key";
    }
    return node->value;
}

int RedBlackBST::size(Node *node) {
    return node == NULL ? 0 : node->count;
}

int RedBlackBST::size() {
    return size(root);
}

Node * RedBlackBST::getNode(Node *node, int key) {
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

Node * RedBlackBST::min(Node *node) {
    if (node->left == NULL) {
        return node;
    }
    return min(node->left);
}

Node * RedBlackBST::max(Node *node) {
    if (node->right == NULL) {
        return node;
    }
    return max(node->right);
}

char RedBlackBST::min() {
    return min(root)->value;
}

char RedBlackBST::max() {
    return max(root)->value;
}

