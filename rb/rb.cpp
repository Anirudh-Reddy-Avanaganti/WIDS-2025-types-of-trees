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
{if(start==nullptr){start=newnodePtr;return;}
	if(start->data <newnodePtr->data)
	insert(start->right,newnodePtr);
	else insert(start->left,newnodePtr);
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
 if(loc->parent==nullptr)root=x;
 else if((loc->parent)->right==loc)(loc->parent)->right=x;
 else (loc->parent)->left=x;
  x->parent=loc->parent;
 	x->right=loc;
  loc->parent=x;
}

// Function performing left rotation
// of the passed node
void RedBlackTree::leftrotate(ptr loc)
{node* x=loc->right;
 loc->right=x->left;
 if(x->left!=nullptr)(x->left)->parent=loc;
 if(loc->parent==nullptr)root=x;
 else if((loc->parent)->left==loc)(loc->parent)->left=x;
 else (loc->parent)->right=x;
  x->parent=loc->parent;
 	x->left=loc;
  loc->parent=x;
}

// This function fixes violations
// caused by RBT insertion
void RedBlackTree::fixup(ptr loc)
{
	while(loc!=root && loc->parent->color==1){
		if(loc->parent->parent->left==loc->parent){
			ptr uncle=loc->parent->parent->right;
			if(uncle!=nullptr && uncle->color==1){
				uncle->color=0;loc->parent->color=0;
				loc->parent->parent->color=1;
			loc=loc->parent->parent;}
			else{
				if(loc->parent->right==loc){leftrotate( loc->parent);
				rightrotate(loc->parent);
					loc->color=0;
					loc->right->color=1;					   }
				else {rightrotate(loc->parent->parent);
							loc->parent->right->color=1;
					 loc->parent->color=0;}
			}
		}
			else{
				ptr uncle=loc->parent->parent->left;
			if(uncle!=nullptr && uncle->color==1){
				uncle->color=0;loc->parent->color=0;
				loc->parent->parent->color=1;
					loc=loc->parent->parent;}
			else{
				if(loc->parent->left==loc){rightrotate(loc->parent);
				leftrotate(loc->parent);
						loc->color=0;
					loc->left->color=1;					  }
											else {leftrotate(loc->parent->parent);
												 loc->parent->left->color=1;
					 loc->parent->color=0;}
			}
			}
		root->color=0;
	}
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




