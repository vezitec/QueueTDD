#include "queue.hpp"
#include <iostream>

// constructors
Queue::Queue() : frontPtr{nullptr}, backPtr{nullptr} {}
//destructors
Queue::~Queue()
{
    while (!isEmpty())
    {
        pop();
        std::cout<<"Removed one Node from the dynamic memory"<<std::endl;
    }
}

// methods
bool Queue::isEmpty()
{
    return !frontPtr && !backPtr;
}

void Queue::push(int value)
{

    if (isEmpty())
    {
        frontPtr = new Node(value);
        backPtr = frontPtr;
    }

    else
    {
        backPtr->nextNodePtr = new Node(value);
        backPtr = backPtr->nextNodePtr;
    }

    size++;
}
void Queue::pop()
{
    if (size > 1)
    {
        Node *currentPtr = frontPtr;
        frontPtr = frontPtr->nextNodePtr;
        delete currentPtr;
        currentPtr = nullptr;
    }
    if (size == 1)
    {
        delete frontPtr;
        frontPtr =nullptr;
        backPtr =nullptr;

    }

      if (size == 0)
    {
        std::cout<<"Queue is already empty."<<std::endl;
    }

    size--;
}

int Queue::front()
{
    return frontPtr->m_value;
}

int Queue::back()
{
    return backPtr->m_value;
}