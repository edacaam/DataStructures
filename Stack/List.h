class Node
{
public:
	double data;
	Node* nextNode;
};
class List
{
public:
	List(void);
	bool isEmpty();
	void insertNode(double data);
	void deleteNode();
	void displayList(void);
	void Clear();
	Node* head;
};