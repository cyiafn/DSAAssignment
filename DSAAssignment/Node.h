#pragma once
/** A node on the queue. */
#include <string>
using namespace std;
struct Node
{
	/** A data item on the queue. */
	string name, description;
	double price, hitcount;

	/** Pointer to next node.     */
	Node    *next;
}; // end Node