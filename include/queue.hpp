

class Queue
{
public:
//constructors
Queue();

//methods
bool isEmpty();
void push(int value);

private:
int * frontPtr;
int * backPtr;
};