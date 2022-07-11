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
	vector<User> users = tokenize("Register.txt", (string)" ");
	for (User u : users)
		u.print();

	unsigned short int optionMenu, optionReg, optionLog;

	system("cls");
	Menu();
	cin >> optionMenu;
	system("cls");

	vector<string> userData;

	int isValid;
	roleType role;

	do {
		if (optionMenu == 1 || optionMenu == 2
			|| optionMenu == 3)
		{
			switch (optionMenu)
			{
			case 1:
				userData = readUserData();
				isValid = 0;
				for (User u : users)
				{

					if (u.getUsername() == userData[0] && u.getPassword() == userData[1])
					{
						isValid = 1;
						role = u.getRole();
						break;
					}
				}

				if (isValid)
				{
					if (role == client)
						cout << "Welcome mr client";
					else if (role == administrator)
						cout << "Welcome mr admin";
				}
				else
					cout << "Invalid username or password";

				cin.get();

				break;
				
			case 2:
				RegisterMenu();
				cin >> optionReg;
				if (optionReg == 1)
				{
					system("cls");
					RegisterClientMenu();
					RegisterClient(users);
				}
				else if (optionReg == 2)
				{
					system("cls");
					RegisterAdminMenu();
					RegisterAdmin(users);
				}
				if (optionReg != 0)
				{
					main();
				}
				
			case 3:
				return 0;
				break;
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

	} while (flag == 0);


	return 0;
}