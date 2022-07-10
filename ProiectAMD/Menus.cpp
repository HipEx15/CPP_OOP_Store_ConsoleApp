#include <iostream>
#include <string>
#include <fstream>
#include "Menus.h"

using namespace std;

int User::numberID = 0;

void Menu(void)
{
	cout << "\n\t---AMD SHOP---\n\t";
	cout << "\nChose your option: ";
	cout << "\n 1 - Login";
	cout << "\n 2 - Register";
	cout << "\n 3 - Exit";
	cout << "\nOption: ";
}

void LoginMenu(void)
{
	std::cout << "\nChose your option: ";
	std::cout << "\n 1 - Login as client";
	std::cout << "\n 2 - Login as administrator";
	std::cout << "\nOption: ";
}

void LoginAdminMenu(void)
{
	std::cout << "\n\t---AMD SHOP---\n\t";
	std::cout << "\nLogin as administrator: \n";
}

void LoginClientMenu(void)
{
	std::cout << "\n\t---AMD SHOP---\n\t";
	std::cout << "\nLogin as client: \n";
}

void LogInClient(void)
{
	bool isFoundLogin = 0, isFoundPassword = 0;
	unsigned int numberofT = 0;
	string Name, Password;

	cin.get();

	cout << "\nUsername: ";
	getline(std::cin, Name);

	cout << "\nPassword: ";
	getline(std::cin, Password);

	ifstream log("Register.txt");

	while (!log.eof())
	{
		string temp = "";
		getline(log, temp);
		
		std::cout << temp << "\n";
		for (int i = 0; i < Name.size(); i++)
		{
			if (temp[i] == Name[i])
				isFoundLogin = 1;
			else
			{
				isFoundLogin = 0;
				break;
			}
		}

		if (isFoundLogin)
		{
			getline(log, temp);

			for (int i = 0; i < Password.size(); i++)
			{
				if (temp[i] == Password[i])
					isFoundPassword = 1;
				else
				{
					isFoundPassword = 0;
					break;
				}
			}
		}

	}

	if (log.eof() && (!isFoundPassword) && (!isFoundLogin))
	{
		cout << "Incorrect username or password.\n";
	}
	else
	{
		cout << "Succesfully login.\n";
	}


	log.close();
}

void RegisterMenu(void)
{
	std::cout << "\nChose your option: ";
	std::cout << "\n 1 - Register as client";
	std::cout << "\n 2 - Register as administrator";
	std::cout << "\nOption: ";
}

void RegisterAdminMenu(void)
{
	std::cout << "\n\t---AMD SHOP---\n\t";
	std::cout << "\nRegister as administrator: \n";
}

void RegisterAdmin(vector<Administrator>& admins)
{
	string Name, Password;
	cin.get();

	cout << "\nNew Username: ";
	getline(std::cin, Name);

	cout << "\nNew Password: ";
	getline(std::cin, Password);

	ofstream reg("Register.txt", ios::app);

	Administrator Admin(Name, Password, administrator);

	admins.push_back(Admin);

	reg << Admin.getRole() << " " << Admin.getNumberId() << " " << Admin.getUsername() << " " << Admin.getPassword() << "\n";
	reg.close();
}

void RegisterClientMenu(void)
{
	std::cout << "\n\t---AMD SHOP---\n\t";
	std::cout << "\nRegister as client: \n";
}

void RegisterClient(vector<Client>& clients)
{
	string Name, Password;
	cin.get();

	cout << "\nNew Username: ";
	getline(std::cin, Name);

	cout << "\nNew Password: ";
	getline(std::cin, Password);

	ofstream reg("Register.txt", ios::app);
	
	Client Client(Name, Password, client);

	clients.push_back(Client);

	reg << Client.getRole() << " " << Client.getNumberId() << " " << Client.getUsername() << " " << Client.getPassword() << "\n";
	reg.close();
}