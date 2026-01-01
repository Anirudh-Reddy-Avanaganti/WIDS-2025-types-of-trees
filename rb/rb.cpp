#include "rb.h"
using ptr = RedBlackTree::ptr;

RedBlackTree::RedBlackTree(){}

const ptr RedBlackTree::getRoot() const
{ 
	return root; 
}

ptr RedBlackTree::insert(int data)
{
	ptr newnodePtr = new node(data);
	if (!root) {
		root = newnodePtr;
		root->color = 0; // set root color as black
		return newnodePtr;
	}
	insert(root, newnodePtr);
	return newnodePtr;
}

// auxiliary function to perform RBT insertion of a node
// you may assume start is not nullptr
void RedBlackTree::insert(ptr start, ptr newnodePtr)
{
	// choose direction
	
	// recurse down the tree

	return;
}

// Credits to Adrian Schneider
void RedBlackTree::printRBT(ptr start, const std::string& prefix, bool isLeftChild) const
{
	if (!start) return;

	std::cout << prefix;
	std::cout << (isLeftChild ? "|--" : "|__" );
	// print the value of the node
	std::cout << start->data << "(" << start->color << ")" << std::endl;
	// enter the next tree level - left and right branch
	printRBT(start->left, prefix + (isLeftChild ? "│   " : "    "), true);
	printRBT(start->right, prefix + (isLeftChild ? "│   " : "    "), false);
}

// Function performing right rotation
// of the passed node
void RedBlackTree::rightrotate(ptr loc)
{node* x=loc->left;
 loc->left=x->right;
 if(x->right!=nullptr)(x->right)->parent=loc;
	x->right=loc;
 loc->parent=x;
 if(loc->parent==nullptr)root=x;
 else if((loc->parent)->right==loc)(loc->parent)->right=x;
 else (loc->parent)->left=x;
  x->parent=loc->parent;
}

// Function performing left rotation
// of the passed node
void RedBlackTree::leftrotate(ptr loc)
{node* x=loc->right;
 loc->right=x->left;
 if(x->left!=nullptr)(x->left)->parent=loc;
	x->left=loc;
 loc->parent=x;
 if(loc->parent==nullptr)root=x;
 else if((loc->parent)->left==loc)(loc->parent)->left=x;
 else (loc->parent)->right=x;
  x->parent=loc->parent;
}

// This function fixes violations
// caused by RBT insertion
void RedBlackTree::fixup(ptr loc)
{
	
}

// Function to print inorder traversal
// of the fixated tree
void RedBlackTree::inorder(ptr start) const
{
	if (!start)
		return;
	
	inorder(start->left);
	std::cout << start->data << " ";
	inorder(start->right);
}



