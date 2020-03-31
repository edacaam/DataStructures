#include "SplayTree.h"
#include<iostream>
#include<stdlib.h>
using namespace std;
/**
	@brief:			Bu fonksiyon agaca dugum ekleme yapmaya yarar..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
void SplayTree::insert(int data)
{
	Insert(data);
}
/**
	@brief:			Bu fonksiyon agactan dugum silmeye yarar..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
void SplayTree::Delete(int data)
{
	remove(data);
}
/**
	@brief:			Bu fonksiyon preorder gezinmeye yarar..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
void SplayTree::Preorder()
{
	preorder();
}
/**
	@brief:			Bu fonksiyon inorder gezinmeye yarar..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
void SplayTree::Inorder()
{
	inorder();
}
/**
	@brief:			Bu fonksiyon postorder gezinmeye yarar..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
void SplayTree::Postorder()
{
	postorder();
}
/**
	@brief:			Bu fonksiyon agacýn boyutunu bulmaya yarar..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
int SplayTree::size()
{
	return Size();
}
/**
	@brief:			Bu fonksiyon agacý goruntulemeye yarar..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
void SplayTree::display()
{
	print2D(root);
}
/**
	@brief:			Bu fonksiyon secili dugumun saga dondurulmesine yarar..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
BSTNode* SplayTree::rightRotate(BSTNode* x)
{
	BSTNode* y = x->left;
	x->left = y->right;
	y->right = x;
	return y;
}
/**
  @brief:		Bu fonksiyon secili dugumun sola dondurulmesine yarar..
  @see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
  */
BSTNode* SplayTree::leftRotate(BSTNode* x)
{
	BSTNode* y = x->right;
	x->right = y->left;
	y->left = x;
	return y;
}

BSTNode* SplayTree::splay(BSTNode* root, int key)
{
	
	if (root == NULL || root->data == key)///Agacda dugum olmamasi veya aranan dugumun kok olmasi durumu
		return root;

	///Aranan dugumun kokten kucuk olmasi durumu
	if (root->data > key)
	{
		
		if (root->left == NULL) return root;

		///Aranan dugumun kokun cocugundan kucuk olmasi durumu   
		if (root->left->data > key)//zig-zig
		{
		
			root->left->left = splay(root->left->left, key); 
			root = rightRotate(root);
		}
		///Aranan dugumun kokun cocugundan buyuk olmasi durumu 
		else if (root->left->data < key) // zig-zag  
		{
	 
			root->left->right = splay(root->left->right, key); 
			if (root->left->right != NULL)
				root->left = leftRotate(root->left);
		}

		///Ikinci rotasyon yapilir 
		return (root->left == NULL) ? root : rightRotate(root);
	}
	else ///Aranan dugumun kokten buyuk olmasi durumu
	{
		if (root->right == NULL) return root;
		
		///Aranan dugumun kokun cocugundan kucuk olmasi durumu   
		if (root->right->data > key)// Zag-Zig
		{
			root->right->left = splay(root->right->left, key);
			if (root->right->left != NULL)
				root->right = rightRotate(root->right);
		}
		///Aranan dugumun kokun cocugundan buyuk olmasi durumu   
		else if (root->right->data < key)// Zag-Zag 
		{
			root->right->right = splay(root->right->right, key);
			root = leftRotate(root);
		}

		///Ikinci rotasyon yapilir  
		return (root->right == NULL) ? root : leftRotate(root);
	}
}
BSTNode* SplayTree::search(BSTNode* root,int key)
{
	return splay(root, key);
	cout <<"New Root:"<<root << endl;

}
