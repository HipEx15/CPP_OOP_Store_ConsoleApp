#include <iostream>
#include <vector>
#include <fstream>
#include "Director.h"
#include "User.h"
#include "Administrator.h"
#include "Client.h"
#include "Menus.h"

using namespace std;

int flag = 0;

int main(void)
{
	//Administrator Admin((string)"Dan", (string)"123456", administrator);
	//Client Client((string)"Alex", (string)"whatever", client);

	//ifstream createProducts;
	//vector<string> products;
	//string temp;

	//createProducts.open("CreateProducts.txt");
	//if (!createProducts)
	//{
	//	cerr << "\nError: file could nnot be opened\n";
	//	exit(1);
	//}
	//while (getline(createProducts,temp))
	//{
	//	products.push_back(temp);
	//}

	//createProducts.close();
	//cout << "\nVECTORUL ESTE: ";
	//for (auto i : products)
	//	cout << i << " ";
	//cout << "\nSFARSIT";

	////FinalProduct* P;
	//FinalCPU* C;
	//FinalGPU* G;
	//FinalAPU* A;

	//BuildCPU BC;
	//BuildGPU BG;
	//BuildAPU BA;

	//Director Dir;

	//Dir.setBuilder(&BC);
	//C = Dir.getFC(54,23,44,4,8,3.6,6,12,(string)"AM4");
	////C->Print();

	//Dir.setBuilder(&BG);
	//G = Dir.getFG(22, 14, 65, 2, 7, 3.6, (string)"1920x1080", DirectX);
	////G->Print();

	//Dir.setBuilder(&BA);
	//A = Dir.getFA(12, 13, 14, 15, 16, 17.5, 4, 8, (string)"AM4+", (string)"1280x760", OpenGL);
	////A->Print();


	////VECTORUL CU TOATE OBIECTELE
	///*vector<Inventory*> Inventory;
	//Inventory.push_back(C);
	//Inventory.push_back(G);
	//Inventory.push_back(A);

	//for (auto i : Inventory)
	//	i->Print();*/

	//Admin.addItem(C);
	//Admin.addItem(G);
	//Admin.addItem(A);
	//vector<Inventory*> inventory = Admin.getInventory();


	//Client.addItem(C, inventory);
	//Client.printBasket();

	////Admin.printInventory();

	////Admin.removeItem(A);
	////Admin.printInventory();

	unsigned short int optionMenu, optionReg, optionLog;

	/*system("cls");
	Menu();
	cin >> optionMenu;
	system("cls");

	switch (optionMenu)
	{
	case 1:
		LoginMenu();
		cin >> optionLog;
		if (optionLog == 1)
		{
			system("cls");
			LoginClientMenu();
			LogInClient();

		}
		else if (optionLog == 2)
		{
			system("cls");

		}
		break;
	case 2:
		RegisterMenu();
		cin >> optionReg;
		if (optionReg == 1)
		{
			system("cls");
			RegisterClientMenu();
			RegisterClient();
		}
		else if (optionReg == 2)
		{
			system("cls");
			RegisterAdminMenu();
			RegisterAdmin();
		}
		if (optionReg != 0)
			main();
	case 3:
		return 0;
	default:
		system("cls");
		main();
		break;
	}*/

	system("cls");
	Menu();
	cin >> optionMenu;
	system("cls");

	vector<Administrator> admins;
	vector<Client> clients;

	do {
		if (optionMenu == 1 || optionMenu == 2
			|| optionMenu == 3) 
		{
			switch (optionMenu)
			{
			case 1:
				LoginMenu();
				cin >> optionLog;
				if (optionLog == 1)
				{
					system("cls");
					LoginClientMenu();
					LogInClient();

				}
				else if (optionLog == 2)
				{
					system("cls");

				}
				break;
			case 2:
				RegisterMenu();
				cin >> optionReg;
				if (optionReg == 1)
				{
					system("cls");
					RegisterClientMenu();
					RegisterClient(clients);
				}
				else if (optionReg == 2)
				{
					system("cls");
					RegisterAdminMenu();
					RegisterAdmin(admins);
				}
				if (optionReg != 0)
				{
					main();
				}
				
			case 3:
				return 0;
			default:
				system("cls");
				main();
				break;
			}
		}
		else
		{
			flag = 1;
		}
	
}while (flag == 0);

	return 0;
}