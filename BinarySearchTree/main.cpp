#include<iostream>
#include<stdlib.h>
#include "BST.h"
using namespace std;
#include<locale.h>
/**
	@author:		Eda CAM --> e-mail: caam.edaa@gmail.com
	@date:			2 Aralik 2019 Pazartesi
	@brief:			Bu kod parcacigi hiyerarsik yap�da kay�t sistemi olusturmaya yarar.
*/
int main()
{
	BST tree;

	setlocale(LC_ALL, "Turkish");
	int choice, id;
	do {

		cout << "Ne yapmak istiyorsunuz?" << endl;
		cout << "1-Asker kaydet" << endl;
		cout << "2-Asker g�nder" << endl;
		cout << "3-Askerleri listele" << endl;
		cout << "4-Asker n�fusunu hesapla" << endl;
		cout << "5-Hiyerar�iyi g�ster." << endl;
		cout << "6-��k��." << endl;
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
			cout << "�nce aslar, sonra �stler:" << endl;
			tree.preorder();
			cout << "Bir as, bir �st:" << endl;
			tree.inorder();
			cout << "�nce �stler, sonra aslar:" << endl;
			tree.postorder();
			break;
		case 4:
			cout << "Ko�u�taki asker say�s�: " << tree.Size()<< endl;
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
