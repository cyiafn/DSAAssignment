//
//  Queue.cpp
//  Week 5
//
//  Created by Chen Yifan on 27/11/16.
//  Copyright © 2016 Chen Yifan. All rights reserved.
//
#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include "Queue.h"
#include "TreapNode.h"
using namespace std;

Queue::Queue()
{
    frontNode = NULL;
    backNode = NULL;
}

Queue::~Queue(){
    
    while (!isEmpty())
    {
        dequeue();
    }
}

bool Queue::enqueue(TreapNode& newItem)
{
    Node *newNode = new Node;
    newNode->item = newItem;
    newNode->next = NULL;
    
    if (isEmpty())
    {
        frontNode = newNode;
    }
    else
    {
        backNode->next = newNode;
    }
    
    //Set back node's pointer to point to new Node
    backNode = newNode;
    return true;
}

TreapNode Queue::dequeue()
{
    if (frontNode == backNode){
		Node *tmpPtr = frontNode;
        frontNode = NULL;
        backNode = NULL;
		return tmpPtr->item;
    }
    else
    {
        Node *tmpPtr = frontNode;
        frontNode = frontNode->next;
        tmpPtr->next = NULL;
        return tmpPtr->item;
    }
}

bool Queue::dequeue(TreapNode& item)
{
    if (frontNode == backNode)
    {
        item = frontNode->item;
        frontNode = NULL;
        backNode = NULL;
    }
    else
    {
        Node *tmpPtr = frontNode;
        frontNode = frontNode->next;
        item = tmpPtr->item;
        tmpPtr->next = NULL;
        delete tmpPtr;
    }
    return true;
}

void Queue::getFront(TreapNode& item)
{
    //Check if queue empty
    if (!isEmpty())
    {
        item = frontNode->item;
    }
}

void Queue::displayItems()
{
    Queue *tmpQueue = new Queue;
    cout << "Displaying all items in queue." << endl << endl;
    while (!isEmpty())
    {
        TreapNode tmp;
        dequeue(tmp);				//Get Item out
        cout << tmp.name << " " << tmp.description << " " << tmp.price << " " << tmp.hitcount << endl;		//Print information
        tmpQueue->enqueue(tmp);		//Place in temporary queue
    }
    
    //Put it back into the queue
    while (!tmpQueue->isEmpty()){
        TreapNode tmp;
        tmpQueue->dequeue(tmp);				//Get Item out
        enqueue(tmp);		//Place in queue
    }
}

bool Queue::isEmpty()
{
    if (frontNode == NULL)
    {
        return true;
    }
    return false;
}
