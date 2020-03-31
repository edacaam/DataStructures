#include<iostream>
#define size 10
using namespace std;

class BankQueue
{

private:
	int items[size];
	int	front;
	int rear;
	int count = 0;

public:
	BankQueue();
	~BankQueue();
	bool isFull();
	bool isEmpty();
	void enQueue(int);
	void deQueue();
	void display();
	void Counter();
};


