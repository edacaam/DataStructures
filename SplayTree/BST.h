#pragma once
#include<string>
struct BSTNode
{
	BSTNode* right;
	BSTNode* left;

	int data;
};
class BST
{
private:
	BSTNode* doFind(BSTNode*, int);
	BSTNode* Min(BSTNode*);
	BSTNode* Max(BSTNode*);
	void preorder(BSTNode*);
	void postorder(BSTNode*);
	void inorder(BSTNode*);
	void destroyTree(BSTNode*);
	int binarytree_count(BSTNode*);
	BSTNode* remove(BSTNode* leaf, int key);
public:
	
	BSTNode* root;
	BST();
	~BST();
	void Insert(int);

	BSTNode* Find(int);
	BSTNode* Min();
	BSTNode* Max();
	void preorder();
	void postorder();
	void inorder();
	void destroyTree();
	int Size(BSTNode*);
	int Size();
	BSTNode* remove(int key);
	void print2DUtil(BSTNode* root, int space);
	void print2D(BSTNode* root);
};


