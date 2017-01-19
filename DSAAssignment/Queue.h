//
//  Queue.h
//  Week 5
//
//  Created by Chen Yifan on 27/11/16.
//  Copyright © 2016 Chen Yifan. All rights reserved.
//

#ifndef Queue_h
#define Queue_h
/** @file Queue.h */
#include "stdafx.h"
#include "TreapNode.h"
typedef char ItemType;

/** ADT queue - Pointer-based implementation. */
class Queue
{
private:
    /** A node on the queue. */
    struct Node
    {
        /** A data item on the queue. */
        TreapNode item;
        /** Pointer to next node.     */
        Node    *next;
    }; // end Node
    
    /** Pointer to front node in the queue. */
    Node *frontNode;
    /** Pointer to back node in the queue. */
    Node *backNode;
    
public:
    
    /** Default constructor. */
    Queue();
    
    /** Destructor. */
    ~Queue();
    
    // Queue operations:
    bool isEmpty();
    bool enqueue(TreapNode& item);
    TreapNode dequeue();
    bool dequeue(TreapNode& item);
    void getFront(TreapNode& item);
    void displayItems();
    
}; // end Queue
// End of header file.

#endif /* Queue_h */
