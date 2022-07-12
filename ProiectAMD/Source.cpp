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
std::vector<Inventory*> inventory;

////TO DO : o multime de id-uri {1,2,3,4,5,6} si sterg 3 si adaug 1 => {1,2,4,5,6,7}

enum states {
	homescreen,
	login,
	reg,
	clientMenu,
	adminMenu
};

int main(void)
{
	vector<User> users = initiateMembers("Register.txt", (string)" ");
	vector<Inventory*> inventory = ReadInventory("Inventory.txt", (string)" ");

	unsigned short int optionMenu, optionReg, optionLog, optionAdmin, optionClient;

	string itemtoRemove;
	string clientRoletochange;

	states state = homescreen;

	vector<string> userData;

	int isValid;
	roleType role;

	do {
		system("cls");
		//homescreen
		if (state == homescreen) {
			Menu();
			cin >> optionMenu;
			switch (optionMenu) {
			case 1:
				state = login;
				break;
			case 2:
				state = reg;
				break;
			case 3:
				flag = 1;
				break;
			}
		}
		else
			//login
			if (state == login) {
				LoginMenu();
				userData = readUserData();

				//check validity of user data
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

				if (isValid == 1)
				{
					if (role == client)
						state = clientMenu;
					else
						state = adminMenu;
				}
				else
				{
					cout << "Invalid username or password!\n";
				}

			}
			else
				//register
				if (state == reg) {
					if (users.size() == 0) {
						RegisterMenuEmpty();
						userData = readUserData();
						ofstream reg("Register.txt", ios::app);
						Administrator admin(1, userData[0], userData[1], administrator);
						users.push_back(admin);
						reg << admin.getRole() << " " << admin.getNumberId() << " " << admin.getUsername() << " " << admin.getPassword() << "\n";
						reg.close();
					}
					else
					{
						RegisterMenu();
						cin >> optionReg;
						if (optionReg == 1)
						{
							system("cls");
							RegisterClientMenu();
							userData = readUserData();
							isValid = 0;
							for (User u : users)
							{

								if (u.getUsername() == userData[0])
								{
									isValid = 1;
									break;
								}
							}

							if (isValid)
								cout << "Invalid username or password";
							else
							{
								ofstream reg("Register.txt", ios::app);
								Client customer(users[users.size() - 1].getID() + 1, userData[0], userData[1], client);
								users.push_back(customer);
								reg << customer.getRole() << " " << customer.getNumberId() << " " << customer.getUsername() << " " << customer.getPassword() << "\n";
								reg.close();

							}
						}
						else if (optionReg == 2)
						{
							RegisterAdminMenu();
							userData = readUserData();
							isValid = 0;
							for (User u : users)
							{
								if (u.getUsername() == userData[0])
								{
									isValid = 1;
									break;
								}
							}

							if (isValid)
								cout << "Invalid username or password";
							else
							{
								ofstream reg("Register.txt", ios::app);
								Administrator admin(users[users.size() - 1].getID() + 1, userData[0], userData[1], administrator);
								users.push_back(admin);
								reg << admin.getRole() << " " << admin.getNumberId() << " " << admin.getUsername() << " " << admin.getPassword() << "\n";
								reg.close();

							}
						}

					}

					if (isValid == 0)
						state = homescreen;

				}
				else
					//client
					if (state == clientMenu) {
						ClientMenu();
						cin >> optionClient;
						switch (optionClient) {
						case 0:
							state = homescreen;
							break;
						case 9:
							flag = 1;
							break;
						}
					}
					else
						//admin
						if (state == adminMenu) {
							AdminMenu();
							cin >> optionAdmin;
							switch (optionAdmin)
							{
							case 0:
								state = homescreen;
								break;
							case 9:
								flag = 1;
								break;

							case 1:
								system("cls");
								addItem(inventory, "Inventory.txt");
								break;
							case 2:
								system("cls");
								cout << "\nThe list of items in shop: \n";
								for (auto i : inventory)
									i->Print();
								std::cout << "\nEnter item name to remove: ";
								cin >> itemtoRemove;
								removeItem(itemtoRemove, "Inventory.txt");
								inventory = ReadInventory("Inventory.txt", (string)" ");
								break;
							case 3:
								system("cls");
								cout << "\nThe list of clients: \n";
								for (auto i : users)
									if (i.getRole() == client)
										i.print();
								std::cout << "\nEnter client name to change his role: ";
								cin >> clientRoletochange;
								modifyRoleType(clientRoletochange, users, administrator);
							default:
								break;
							}
						}


	} while (flag == 0);


	return 0;
}