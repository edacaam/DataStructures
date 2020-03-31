#include<iostream>
#include<stdlib.h>
#include "BST.h"
using namespace std;
#include<locale.h>
/**
	@author:		Eda CAM --> e-mail: caam.edaa@gmail.com
	@date:			2 Aralik 2019 Pazartesi
	@brief:			Bu kod parcacigi hiyerarsik yapýda kayýt sistemi olusturmaya yarar.
*/
int main()
{
	BST tree;

	setlocale(LC_ALL, "Turkish");
	int choice, id;
	do {

		cout << "Ne yapmak istiyorsunuz?" << endl;
		cout << "1-Asker kaydet" << endl;
		cout << "2-Asker gönder" << endl;
		cout << "3-Askerleri listele" << endl;
		cout << "4-Asker nüfusunu hesapla" << endl;
		cout << "5-Hiyerarþiyi göster." << endl;
		cout << "6-Çýkýþ." << endl;
		cin >> choice;
		switch (choice) {

		case 1:
			cout << "Kademe no girin: " << endl;
			cin >> id;
			tree.Insert(id);
			break;
		case 2:
			cout << "Kademe no girin: " << endl;
			cin >> id;
			tree.remove(id);
			break;
		case 3:
			cout << "Önce aslar, sonra üstler:" << endl;
			tree.preorder();
			cout << "Bir as, bir üst:" << endl;
			tree.inorder();
			cout << "Önce üstler, sonra aslar:" << endl;
			tree.postorder();
			break;
		case 4:
			cout << "Koðuþtaki asker sayýsý: " << tree.Size()<< endl;
			break;
		case 5:
					tree.printTree();
					break;
		case 6:
			break;
		default:
			break;
		}

	} while (choice != 7);


}
