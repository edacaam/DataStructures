#pragma once
#include<vector>
struct BSTNode
{
	BSTNode* right;
	BSTNode* left;
	int data;
};
struct Trunk
{
	Trunk* prev;
	char str;

	Trunk(Trunk* prev, char str)
	{
		this->prev = prev;
		this->str = str;
	}
};
class BST
{
private:
	char str;
	Trunk* p;
	BSTNode* doFind(BSTNode*, int);
	BSTNode* Min(BSTNode*);
	BSTNode* Max(BSTNode*);
	void preorder(BSTNode*);
	void postorder(BSTNode*);
	void inorder(BSTNode*);
	void printTree(BSTNode* root, Trunk* prev, bool isLeft);
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
	void showTrunks(Trunk* p);
	void printTree();
};
//BSTNode* buildTree(BSTNode* root);
//BSTNode* buildTreeUtil(vector<BSTNode*> &nodes, int start, int end);
//void storeBSTNodes(BSTNode* root, vector<BSTNode*> &nodes);


