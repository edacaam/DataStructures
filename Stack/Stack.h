
#include "List.h"///Liste fonksiyonlarinin yigin islemlerinde kullanilabilmesi icin List.h eklenmistir.

class Stack : private List///Inheritance(Miras) tanimlamasi yapilmistir.
{
public:
	Stack(void);
	~Stack(void);
	double Top();
	void Push(const double data);
	double Pop();
	void DisplayStack();
	void Delete();
};