#include "queue.hpp"

//constructors
Queue::Queue(): frontPtr{nullptr}, backPtr{nullptr}{}

// methods
bool Queue::isEmpty()
{
return !frontPtr && !backPtr;
}