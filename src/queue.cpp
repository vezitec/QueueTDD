#include "queue.hpp"

//constructors
Queue::Queue(): frontPtr{nullptr}, backPtr{nullptr}{}

// methods
bool Queue::isEmpty()
{
return !frontPtr && !backPtr;
}

void Queue::push(int value)
{
    frontPtr = new int (value);
    backPtr = new int (value);
}
void Queue::pop()
{
    if (frontPtr)
    {
        delete frontPtr;
        frontPtr = nullptr;
    }

    if (backPtr)
    {
        delete backPtr;
        backPtr = nullptr;
    }
}

int Queue::front()
{
    return *frontPtr;
}