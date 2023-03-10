#include "quetype.h"
#include <iostream>
using namespace std;

template <class ItemType> //Template declared
QueType<ItemType>::QueType() //Cosntructor
{
    front = NULL;
    rear = NULL;
}

template <class ItemType>
bool QueType<ItemType>::IsEmpty() //Will return true if queue is empty else false
{
    return (front == NULL);
}

template<class ItemType>
bool QueType<ItemType>::IsFull() //Will return true if queue is full
{
    NodeType* location;
    try {
        location = new NodeType;
        delete location;
        return false;
    }
    catch(bad_alloc& exception)
    {
        return true;
    }
}

template <class ItemType>
void QueType<ItemType>::Enqueue(ItemType newItem) //To Enqueue element in queue
{
    if (IsFull())
        throw FullQueue();
    else{
        NodeType* newNode;
        newNode = new NodeType;
        newNode->info = newItem;
        newNode->next = NULL;
        if (rear == NULL)
            front = newNode;
        else
            rear->next = newNode;
        rear = newNode;
    }
}

template <class ItemType>
void QueType<ItemType>::Dequeue(ItemType& item) //To Dequeue element from queue
{
    if(IsEmpty())
        throw EmptyQueue();
    else{
        NodeType* tempPtr;
        tempPtr = front;
        item = front->info;
        front = front->next;
        if(front == NULL)
            rear = NULL;
        delete tempPtr;
    }
}

template <class ItemType>
void QueType<ItemType>::MakeEmpty() //Function to clear the queue
{
    NodeType* tempPtr;
    while (front != NULL)
    {
        tempPtr = front;
        front = front->next;
        delete tempPtr;
    }
    rear = NULL;
}

template <class ItemType>
QueType<ItemType>::~QueType() //Destructor
{
    MakeEmpty();
}

template <class ItemType>
ItemType QueType<ItemType>::front_element() //Function which will return the frist element of queue
{
    return front->info;
}
