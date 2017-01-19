#include "stdafx.h"
#include <iostream>
#include <string>
#include "TreapNode.h"
#include "Treap.h"

using namespace std;


Treap::Treap()
{
	root = NULL;
}

TreapNode* Treap::rightRotate(TreapNode *y)
{
	TreapNode *x = y->left, *T2 = x->right;
	x->right = y;
	y->left = T2;
	return x;
}

TreapNode* Treap::leftRotate(TreapNode *x)
{
	TreapNode *y = x->right, *T2 = y->left;
	y->left = x;
	x->right = T2;
	return y;
}

TreapNode* Treap::newNode(string name, string description,double price,double hitcount)
{
	TreapNode* temp = new TreapNode;
	temp->name = name;
	temp->description = description;
	temp->price = price;
	temp->hitcount = hitcount;
	temp->left = temp->right = NULL;
	return temp;
}

TreapNode* Treap::search(TreapNode* root, string name)
{
	if (root == NULL || root->name == name)
		return root;
	if (root->name < name)
		return search(root->right, name);
	return search(root->left, name);
}

TreapNode* Treap::insert(TreapNode* root, string name, string description, double price, double hitcount)
{
	if (!root)
		return newNode(name, description, price, hitcount);
	if (name <= root->name)
	{
		root->left = insert(root->left, name, description,price,hitcount);
		if (root->left->hitcount > root->hitcount)
			root = rightRotate(root);
	}
	else
	{
		root->right = insert(root->right, name, description, price, hitcount);
		if (root->right->hitcount > root->hitcount)
			root = leftRotate(root);
	}
	return root;
}

TreapNode* Treap::deleteNode(TreapNode* root, string name)
{
	if (root == NULL)
		return root;

	if (name < root->name)
		root->left = deleteNode(root->left, name);
	else if (name > root->name)
		root->right = deleteNode(root->right, name);
	else if (root->left == NULL)
	{
		TreapNode *temp = root->right;
		delete(root);
		root = temp;
	}
	else if (root->right == NULL)
	{
		TreapNode *temp = root->left;
		delete(root);
		root = temp; 
	}
	else if (root->left->hitcount < root->right->hitcount)
	{
		root = leftRotate(root);
		root->left = deleteNode(root->left, name);
	}
	else
	{
		root = rightRotate(root);
		root->right = deleteNode(root->right, name);
	}
	return root;
}
void Treap::inorder(TreapNode* root)
{
	if (root)
	{
		inorder(root->left);
		cout << "Name: " << root->name << " | Hitcount:  "
			<< root->hitcount;
		if (root->left)
			cout << " | left child: " << root->left->name;
		if (root->right)
			cout << " | right child: " << root->right->name;
		cout << endl;
		inorder(root->right);
	}
	else if (root = NULL)
	{
		cout << "Error" << endl;
	}
}

