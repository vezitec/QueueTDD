

class Queue
{
public:
//constructors
Queue();

//methods
bool isEmpty();
void push(int value);
void pop();


private:
int * frontPtr;
int * backPtr;
};