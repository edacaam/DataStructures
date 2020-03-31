#pragma once
#include "BST.h"
class SplayTree :public BST
{
public:
	
	void insert(int);
	void Delete(int);
	void Preorder();
	void Inorder();
	void Postorder();
	int size();
	void display();
	BSTNode* rightRotate(BSTNode*);
	BSTNode* leftRotate(BSTNode*);
	BSTNode* splay(BSTNode*, int);
	BSTNode* search(BSTNode*,int);
	
};



