
#pragma once
#include <string>
using namespace std;
struct TreapNode
{
	string name, description;
	double price, hitcount;
	TreapNode *left, *right;
};
