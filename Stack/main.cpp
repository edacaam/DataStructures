#include <iostream>
#include "Stack.h"

using namespace std;
/**
	@author:		Eda CAM --> e-mail: caam.edaa@gmail.com
	@date:			25 Kasim 2019 Pazartesi
	@brief:			Bu kod parcacigi bir sayfada Undo Redo gibi islemleri yigin veri yapisi ile gerceklemeye yarar.
*/

	int main() {
		int ch;
		double add;
	    double ret;
		Stack s1, s2;///Undo ve Redo islemlerinin tutulmasi icin iki yigin olustrulmustur.
		while (1) {
			cout << "\nEnter your choice: \n1. Enter a new address \n2. Undo\n3. Redo\n4. Display \n5. Clear\n6. Exit ";
			cout << endl;
			cin >> ch;
			switch (ch) {
			case 1:
				cout << "\nEnter the address :  ";
				cin >> add;
				s1.Push(add);///Undo yiginina veriler itilir.
				break;
			case 2:
				cout << "\n Current location :  ";
				ret = s1.Pop();///Undo islemi icin 1.yigindaki veri cekilip 2.yigina itilir.
				s2.Push(ret);
				ret = s1.Top();
				cout << ret;
				break;
			case 3:
				cout << "\n Current location :  ";
				ret = s2.Pop();///Redo islemi icin 2.yigindaki veri 1.ye geri itilir.
				s1.Push(ret);
				cout << ret;
				break;
			case 4:
				cout << "\nUndo Stack :\n";
				s1.DisplayStack();
				cout << "\nRedo Stack :\n";
				s2.DisplayStack();
				break;
			case 5:
				cout << "\nStacks are Emptied";
				s1.Delete();
				s2.Delete();
				break;
			default:
				cout << "\nLeaving the Application\n";
				exit(1);
			}
		}



		return 0;

	}
