#include "BST.h"
#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;
/**
	@brief:			Bu fonksiyon yapici fonksiyondur..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
BST::BST()
{
	root = NULL;
}
/**
	@brief:			Bu fonksiyon yikici fonksiyondur..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
BST::~BST() {
	destroyTree();
}
/**
	@brief:			Bu fonksiyon yikici fonksiyonu gerceklemeye yarar..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
void BST::destroyTree(BSTNode* leaf) {
	if (leaf != NULL) {
		destroyTree(leaf->left);
		destroyTree(leaf->right);
		delete leaf;
	}
}
/**
	@brief:			Bu fonksiyon yikici fonksiyonu gerceklemeye yarayanin argümansýz versiyonudur ..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
void BST::destroyTree() {
	destroyTree(root);
}
/**
	@brief:			Bu fonksiyon agaca veri eklemeye yarar ..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
void BST::Insert(int key) {
	BSTNode* pp = NULL;  /* pp is the parent of p */
	BSTNode* p = root;   /* Start at the root and go down */
	while (p != NULL) {
		pp = p;
		if (key < p->data)  p = p->left;
		else /* key > p->key */ p = p->right;
	} /* end-while */

	BSTNode* z = new BSTNode(); /* New node to store the key */
	z->data = key; z->left = z->right = NULL;

	if (root == NULL) root = z; /* Inserting into empty tree */
	else if (key < pp->data) pp->left = z;
	else                    pp->right = z;
}
/**
	@brief:			Bu fonksiyon agacta veri aramaya yarar ..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
BSTNode* BST::doFind(BSTNode* root, int key) {
	if (root == NULL)
	{
		cout << "Bulunamadý!" << endl;
		return NULL;
	}
	if (key == root->data)
	{
		cout << "Bulundu!" << root->data << endl;
		return root;
	}
	else if (key < root->data)
		return doFind(root->left, key);
	else /* key > root->key */
		return doFind(root->right, key);
}
/**
	@brief:			Bu fonksiyon agacta veri aramaya yarayan fonksiyonun argumansiz halidir ..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
BSTNode* BST::Find(int key) {
	return doFind(root, key);
}
/**
	@brief:			Bu fonksiyon agactaki en kucuk veriyi bulmaya yarar ..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
BSTNode* BST::Min(BSTNode* root) {
	if (root == NULL)
		return NULL;

	BSTNode* p = root;
	while (p->left != NULL) {
		p = p->left;
	}
	cout << "Min:" << p->data << endl;
	return p;
}
/**
	@brief:			Bu fonksiyon agactaki en buyuk veriyi bulmaya yarar ..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
BSTNode* BST::Max(BSTNode* root) {
	if (root == NULL)
		return NULL;

	BSTNode* p = root;
	while (p->right != NULL) {
		p = p->right;
	}
	cout << "Max:" << p->data << endl;
	return p;
}
/**
	@brief:			Bu fonksiyon agactaki en buyuk veriyi bulmaya yarayan fonksiyonun argumansiz halidir ..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
BSTNode* BST::Max() {
	if (root == NULL)
		return NULL;

	BSTNode* p = root;
	while (p->right != NULL) {
		p = p->right;
	} 
	return p;
}
/**
	@brief:			Bu fonksiyon agactaki en kucuk veriyi bulmaya yarayan fonksiyonun argumansiz halidir ..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
BSTNode* BST::Min() {
	if (root == NULL)
		return NULL;

	BSTNode* p = root;
	while (p->left != NULL) {
		p = p->left;
	}
	return p;
}
/**
	@brief:			Bu fonksiyon agactan dugum silmeye yarar ..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
BSTNode* BST::remove(BSTNode* leaf, int key) {
	if (leaf == NULL) return leaf;
	else if (key < leaf->data) leaf->left = remove(leaf->left, key);
	else if (key > leaf->data) leaf->right = remove(leaf->right, key);
	// Wohoo... I found you, Get ready to be deleted	
	else {
		// Case 1:  No child
		if (leaf->left == NULL && leaf->right == NULL) {
			delete leaf;
			leaf = NULL;
		}
		//Case 2: One child 
		else if (leaf->left == NULL) {
			BSTNode* temp = leaf;
			leaf = leaf->right;
			delete temp;
		}
		else if (leaf->right == NULL) {
			BSTNode* temp = leaf;
			leaf = leaf->left;
			delete temp;
		}
		// case 3: 2 children
		else {
			BSTNode* temp = Min(leaf->right);
			leaf->data = temp->data;
			leaf->right = remove(leaf->right, temp->data);
		}
	}
	return leaf;
}
/**
	@brief:			Bu fonksiyon agactan dugum silmeye yarayan fonksiyonun argumansiz halidir..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
BSTNode* BST::remove(int key)
{

	return remove(root, key);

}
/**
	@brief:			Bu fonksiyon agactainorder dolasmaya yarar ..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
void BST::inorder(BSTNode* p) {
	if (p != NULL) {
		inorder(p->left);
		cout << p->data <<",\t";
		inorder(p->right);
	}

}
/**
	@brief:			Bu fonksiyon agacta inorder dolasmaya yarayan fonksiyonun argumansiz halidir..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
void BST::inorder()
{
	inorder(root);
	cout << endl << endl;
}
/**
	@brief:			Bu fonksiyon agacta preorder dolasmaya yarar ..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
void BST::preorder(BSTNode* p) {
	if (p != NULL) {
		cout << p->data << ",\t";
		preorder(p->left);
		preorder(p->right);
	}

}
/**
	@brief:			Bu fonksiyon agacta preorder dolasmaya yarayanin argumansiz halidir ..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
void BST::preorder()
{
	preorder(root);
	cout << endl << endl;
}
/**
	@brief:			Bu fonksiyon agacta postorder dolasmaya yarar ..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
void BST::postorder(BSTNode* p) {
	if (p != NULL) {
		postorder(p->left);
		postorder(p->right);
		cout << p->data <<",\t";
	}

}
/**
	@brief:			Bu fonksiyon agacta postorder dolasmaya yarayanin argumansiz halidir ..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
void BST::postorder()
{

	postorder(root);
	cout << endl << endl;
}
/**
	@brief:			Bu fonksiyon agactaki dugum sayisini bulmaya yarar ..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
int BST::Size(BSTNode* leaf)
{
	unsigned int count = 1;
	if (leaf->left != NULL) {
		count += Size(leaf->left);
	}
	if (leaf->right != NULL) {
		count += Size(leaf->right);
	}
	return count;

}
/**
	@brief:			Bu fonksiyon agacta dugum sayisini bulmaya yarayanin argumansiz halidir ..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
int BST::Size()
{
	return binarytree_count(root);
}
/**
	@brief:			Bu fonksiyon agactaki dugum sayisini bulmaya yarar ..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
int BST::binarytree_count(BSTNode* leaf)
{
	unsigned int count = 0;
	if (leaf != NULL) {
		count = Size(leaf);
	}
	return count;
}
/**
	@brief:			Bu fonksiyon agactaki dugumleri yazdirmaya yarar ..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
void BST::showTrunks(Trunk* p)
{
	if (p == nullptr)
		return;
	showTrunks(p->prev);
	cout <<p->str;
}
/**

	@brief:			Bu fonksiyon agactaki dugumleri yazdirmaya yarar ..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/

void BST::printTree()
{
	printTree(root, nullptr, false);
}
/**

	@brief:			Bu fonksiyon agactaki dugumleri yazdirmaya yarar ..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/

void BST::printTree(BSTNode* leaf, Trunk* prev, bool isLeft)
{
	if (leaf == nullptr)
		return;

	char prev_str = ' ';
	Trunk* trunk = new Trunk(prev, prev_str);
	printTree(leaf->left, trunk, true);

	if (!prev)
		trunk->str = '---';
	else if (isLeft)
	{
		trunk->str = ' .--';
		prev_str = '  |';
	}
	else
	{
		trunk->str = ' `--';
		prev->str = prev_str;
	}

	showTrunks(trunk);
	cout << leaf->data << endl;
	if (prev)
		prev->str = prev_str;

	trunk->str = '  |';
	printTree(leaf->right, trunk, false);
}
