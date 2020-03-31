#include<iostream>
#include<stdlib.h>
#include"SplayTree.h"
#include"BST.h"
using namespace std;

	/**
		@author:		Eda CAM --> e-mail: caam.edaa@gmail.com
		@date:			10 Aralik 2019 Pazartesi
		@brief:			Bu kod parcacigi hiyerarsik yap�da kay�t sistemi olusturmaya yarar.
	*/
	int main()
	{
		struct BSTNode* root = NULL;
		SplayTree b;
		setlocale(LC_ALL, "Turkish");
		int choice, id;
		do {

			cout << "Ne yapmak istiyorsunuz?" << endl;
			cout << "1-Asker kaydet" << endl;
			cout << "2-Asker g�nder" << endl;
			cout << "3-Askerleri listele" << endl;
			cout << "4-Asker n�fusunu hesapla" << endl;
			cout << "5-Hiyerar�iyi g�ster." << endl;
			cout << "6-Asker Ara." << endl;
			cout << "7-��k��." << endl;
			cin >> choice;
			switch (choice) {

			case 1:
				cout << "Kademe no girin: " << endl;
				cin >> id;
			  b.insert(id);
				break;
			case 2:
				cout << "Kademe no girin: " << endl;
				cin >> id;
				b.Delete(id);
				break;
			case 3:
				cout << "�nce aslar, sonra �stler:" << endl;
				b.Preorder();
				cout << "Bir as, bir �st:" << endl;
				b.Inorder();
				cout << "�nce �stler, sonra aslar:" << endl;
				b.Postorder();
				break;
			case 4:
				cout << "Ko�u�taki asker say�s�: " << b.size() << endl;
				break;
			case 5:
				b.display();
				break;
			case 6:
				
			    cout << "Sayi Giriniz:";
				cin >> id;
				b.root = b.search(b.root, id);
				break;
			case 7:
				break;
			default:
				break;
			}

		} while (choice != 7);

		system("pause");
	}
