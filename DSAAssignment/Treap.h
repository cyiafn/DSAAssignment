#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include "TreapNode.h"
using namespace std;
class Treap
{
public:
	TreapNode* root = NULL;
	Treap();
	TreapNode *rightRotate(TreapNode *y);
	TreapNode *leftRotate(TreapNode *x);
	TreapNode* newNode(string name, string description, double price, double hitcount);
	TreapNode* search(TreapNode* root, string name);
	TreapNode* insert(TreapNode* root, string name, string description, double price, double hitcount);
	TreapNode* deleteNode(TreapNode* root, string name);
	void inorder(TreapNode* root);
};