

class Queue
{
public:
//constructors
Queue();

//methods
bool isEmpty();
void push(int value);
void pop();
int front();


private:
int * frontPtr;
int * backPtr;
};