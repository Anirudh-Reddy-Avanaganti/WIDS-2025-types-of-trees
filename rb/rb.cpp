#include "rb.h"
using ptr = RedBlackTree::ptr;

RedBlackTree::RedBlackTree() : root(nullptr) {}

const ptr RedBlackTree::getRoot() const
{ 
    return root; 
}

ptr RedBlackTree::insert(int data)
{
    ptr newnodePtr = new node(data);

    // CRITICAL: initialize all fields
    newnodePtr->color  = 1;   // RED
    newnodePtr->left   = nullptr;
    newnodePtr->right  = nullptr;
    newnodePtr->parent = nullptr;

    if (!root) {
        root = newnodePtr;
        root->color = 0; // root is always BLACK
        return newnodePtr;
    }

    insert(root, newnodePtr);
    fixup(newnodePtr);
    return newnodePtr;
}

// BST insertion helper
void RedBlackTree::insert(ptr start, ptr n)
{
    if (n->data < start->data) {
        if (start->left)
            insert(start->left, n);
        else {
            start->left = n;
            n->parent = start;
        }
    } else {
        if (start->right)
            insert(start->right, n);
        else {
            start->right = n;
            n->parent = start;
        }
    }
}

// RIGHT ROTATION
void RedBlackTree::rightrotate(ptr loc)
{
    ptr x = loc->left;
    if (!x) return;

    loc->left = x->right;
    if (x->right)
        x->right->parent = loc;

    x->parent = loc->parent;

    if (!loc->parent)
        root = x;
    else if (loc == loc->parent->right)
        loc->parent->right = x;
    else
        loc->parent->left = x;

    x->right = loc;
    loc->parent = x;
}

// LEFT ROTATION
void RedBlackTree::leftrotate(ptr loc)
{
    ptr x = loc->right;
    if (!x) return;

    loc->right = x->left;
    if (x->left)
        x->left->parent = loc;

    x->parent = loc->parent;

    if (!loc->parent)
        root = x;
    else if (loc == loc->parent->left)
        loc->parent->left = x;
    else
        loc->parent->right = x;

    x->left = loc;
    loc->parent = x;
}

// FIX RED-BLACK VIOLATIONS
void RedBlackTree::fixup(ptr loc)
{
    while (loc != root &&
           loc->parent &&
           loc->parent->color == 1 &&
           loc->parent->parent) {

        ptr parent = loc->parent;
        ptr grandparent = parent->parent;

        if (parent == grandparent->left) {
            ptr uncle = grandparent->right;

            // Case 1: Uncle is RED
            if (uncle && uncle->color == 1) {
                parent->color = 0;
                uncle->color = 0;
                grandparent->color = 1;
                loc = grandparent;
            }
            else {
                // Case 2: Triangle
                if (loc == parent->right) {
                    loc = parent;
                    leftrotate(loc);
                }
                // Case 3: Line
                parent->color = 0;
                grandparent->color = 1;
                rightrotate(grandparent);
            }
        }
        else {
            ptr uncle = grandparent->left;

            // Case 1: Uncle is RED
            if (uncle && uncle->color == 1) {
                parent->color = 0;
                uncle->color = 0;
                grandparent->color = 1;
                loc = grandparent;
            }
            else {
                // Case 2: Triangle
                if (loc == parent->left) {
                    loc = parent;
                    rightrotate(loc);
                }
                // Case 3: Line
                parent->color = 0;
                grandparent->color = 1;
                leftrotate(grandparent);
            }
        }
    }

    root->color = 0;
}

// INORDER TRAVERSAL
void RedBlackTree::inorder(ptr start) const
{
    if (!start) return;
    inorder(start->left);
    std::cout << start->data << " ";
    inorder(start->right);
}

// STRUCTURED TREE PRINT
void RedBlackTree::printRBT(ptr start, const std::string& prefix, bool isLeftChild) const
{
    if (!start) return;

    std::cout << prefix;
    std::cout << (isLeftChild ? "|--" : "|__");
    std::cout << start->data << "(" << start->color << ")" << std::endl;

    printRBT(start->left,  prefix + (isLeftChild ? "│   " : "    "), true);
    printRBT(start->right, prefix + (isLeftChild ? "│   " : "    "), false);
}
