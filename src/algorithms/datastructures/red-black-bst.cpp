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
template <typename K, typename V>
class Node {
    // don't seem to be able to have the same typename variables names here
    // or they will shadow the existing ones.
    template <typename X, typename Y>
    friend class RedBlackBST;
    K key;
    V value;
    Node* left;
    Node* right;
    // color of the link from the parent node.
    bool red;
    int count;
    public: 
        Node(K key, V value);
        Node(K key, V value, bool red, int count);
        Node(K key, V value, Node *left, Node *right, bool red = false, int count = 0);
};

template <typename K, typename V>
Node<K,V>::Node(K key, V value) : Node(key, value, nullptr, nullptr, false, 0) {};
template <typename K, typename V>
Node<K,V>::Node(K key, V value, bool red, int count) : Node(key, value, nullptr, nullptr, red, count) {};
template <typename K, typename V>
Node<K,V>::Node(K key, V value, Node *left, Node *right, bool red, int count) {
    this->key = key;
    this->value = value;
    this->left = left;
    this->right = right;
    this->red = red;
    this->count = count;
}

template <typename K, typename V>
class RedBlackBST {
    private:
        Node<K,V> *root;
        Node<K,V> *putNode(Node<K,V> *node, K key, V value);
        Node<K,V> *getNode(Node<K,V> *node, K key);
        Node<K,V> *min(Node<K,V> *node);
        Node<K,V> *max(Node<K,V> *node);
        int size(Node<K,V> *node);
        int rank(const Node<K,V> *node, K key);
        bool isRed(Node<K,V>* node);
        bool hasTwoRedLeftLinks(Node<K,V>* node);
        Node<K,V>* rotateLeft(Node<K,V>* node);
        Node<K,V>* rotateRight(Node<K,V>* node);
        void flipColors(Node<K,V>* node);
    public:
        RedBlackBST() : root(nullptr) {}
        ~RedBlackBST() {}
        void put(K key, V value);
        V get(K key);
        int size();
        V min();
        V max();
        int rank(K key);
};

template <typename K, typename V>
void RedBlackBST<K,V>::put(K key, V value) {
    root = putNode(root, key, value);
}

template <typename K, typename V>
Node<K,V> * RedBlackBST<K,V>::putNode(Node<K,V> *node, K key, V value) {
    if (node == nullptr) {
        return new Node<K,V>(key, value, true, 1);
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

template <typename K, typename V>
bool RedBlackBST<K,V>::isRed(Node<K,V>* node) {
    return node == nullptr ? false :node->red;
}

template <typename K, typename V>
bool RedBlackBST<K,V>::hasTwoRedLeftLinks(Node<K,V>* node) {
    if (node->left == nullptr) {
        return false;
    }
    if (node->left->left == nullptr) {
        return false;
    }
    return isRed(node->left) && isRed(node->left->left);
}

template <typename K, typename V>
void RedBlackBST<K,V>::flipColors(Node<K,V> *node) {
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
template <typename K, typename V>
Node<K,V> * RedBlackBST<K,V>::rotateLeft(Node<K,V> *parent) {
    Node<K,V> *newParent = parent->right;
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
template <typename K, typename V>
Node<K,V> * RedBlackBST<K,V>::rotateRight(Node<K,V> *parent) {
    Node<K,V> *newParent = parent->left;
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
template <typename K, typename V>
int RedBlackBST<K,V>::rank(const Node<K,V> *node, K key) {
    if (node == nullptr) {
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

template <typename K, typename V>
int RedBlackBST<K,V>::rank(K key) {
    return rank(root, key);
}

template <typename K, typename V>
V RedBlackBST<K,V>::get(K key) {
    Node<K,V> *node = getNode(root, key);
    if (node == nullptr) {
        throw "No such key";
    }
    return node->value;
}

template <typename K, typename V>
int RedBlackBST<K,V>::size(Node<K,V> *node) {
    return node == nullptr ? 0 : node->count;
}

template <typename K, typename V>
int RedBlackBST<K,V>::size() {
    return size(root);
}

template <typename K, typename V>
Node<K,V> * RedBlackBST<K,V>::getNode(Node<K,V> *node, K key) {
    if (node == nullptr) {
        return nullptr;
    }
    if (key < node->key) {
        return getNode(node->left, key);
    } else if (key > node->key) {
        return getNode(node->right, key);
    } else {
        return node;
    }
}

template <typename K, typename V>
Node<K,V> * RedBlackBST<K,V>::min(Node<K,V> *node) {
    if (node->left == nullptr) {
        return node;
    }
    return min(node->left);
}

template <typename K, typename V>
Node<K,V> * RedBlackBST<K,V>::max(Node<K,V> *node) {
    if (node->right == nullptr) {
        return node;
    }
    return max(node->right);
}

template <typename K, typename V>
V RedBlackBST<K,V>::min() {
    return min(root)->value;
}

template <typename K, typename V>
V RedBlackBST<K,V>::max() {
    return max(root)->value;
}

