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
    newnodePtr->color = 1; // NEW NODE MUST BE RED

    if (!root) {
        root = newnodePtr;
        root->color = 0; // root is always BLACK
        return newnodePtr;
    }

    insert(root, newnodePtr);
    fixup(newnodePtr);
    return newnodePtr;
}

// auxiliary function to perform BST insertion
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
    loc->left = x->right;

    if (x->right != nullptr)
        x->right->parent = loc;

    x->parent = loc->parent;

    if (loc->parent == nullptr)
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
    loc->right = x->left;

    if (x->left != nullptr)
        x->left->parent = loc;

    x->parent = loc->parent;

    if (loc->parent == nullptr)
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
    while (loc != root && loc->parent->color == 1) {

        // Parent is LEFT child
        if (loc->parent == loc->parent->parent->left) {

            ptr uncle = loc->parent->parent->right;

            // Case 1: Uncle is RED
            if (uncle != nullptr && uncle->color == 1) {
                loc->parent->color = 0;
                uncle->color = 0;
                loc->parent->parent->color = 1;
                loc = loc->parent->parent;
            }
            else {
                // Case 2: Triangle
                if (loc == loc->parent->right) {
                    loc = loc->parent;
                    leftrotate(loc);
                }
                // Case 3: Line
                loc->parent->color = 0;
                loc->parent->parent->color = 1;
                rightrotate(loc->parent->parent);
            }
        }
        // Parent is RIGHT child (mirror cases)
        else {

            ptr uncle = loc->parent->parent->left;

            if (uncle != nullptr && uncle->color == 1) {
                loc->parent->color = 0;
                uncle->color = 0;
                loc->parent->parent->color = 1;
                loc = loc->parent->parent;
            }
            else {
                if (loc == loc->parent->left) {
                    loc = loc->parent;
                    rightrotate(loc);
                }
                loc->parent->color = 0;
                loc->parent->parent->color = 1;
                leftrotate(loc->parent->parent);
            }
        }
    }

    root->color = 0; // root must be BLACK
}

// INORDER TRAVERSAL
void RedBlackTree::inorder(ptr start) const
{
    if (!start) return;
    inorder(start->left);
    std::cout << start->data << " ";
    inorder(start->right);
}
