#include <iostream>
#include <string>
#include <fstream>
#include "Menus.h"

using namespace std;

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
	std::cout << "\n\t---AMD SHOP---\n\t";
	std::cout << "\nPlease login: \n";
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

void RegisterMenuEmpty(void)
{
	std::cout << "\n\t---AMD SHOP---\n\t";
	std::cout << "\nEmpty shop, please register as admin: \n";
}

void RegisterClientMenu(void)
{
	std::cout << "\n\t---AMD SHOP---\n\t";
	std::cout << "\nRegister as client: \n";
}

void ClientMenu(void)
{
	std::cout << "\n\t---AMD SHOP---\n\t";
	std::cout << "\nClient menu: ";
	std::cout << "\n 1 - Add product to basket";
	std::cout << "\n 2 - Remove product to basket";
}

void AdminMenu(void)
{
	std::cout << "\n\t---AMD SHOP---\n\t";
	std::cout << "\nAdministrator menu: \n";
	std::cout << "\n 1 - Add product to inventory";
	std::cout << "\n 2 - Remove product to inventory";
	std::cout << "\n 3 - Add admin";
}


vector<string> readFile(string fileName)
{
	vector<string> lines;
	string line;
	ifstream myfile(fileName);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			lines.push_back(line);
		}
		myfile.close();
	}
	else
	{
		cout << "Unable to open file";
	}
	return lines;
}

vector<User> tokenize(string filepath, string del)
{
	vector<string> tokens = readFile(filepath);

	vector<User> users;

	for (string token : tokens)
	{
		vector<string> userData;

		int start = 0;
		int end = token.find(del);
		while (end != -1) 
		{
			userData.push_back(token.substr(start, end - start));
			start = end + del.size();
			end = token.find(del, start);
		}

		userData.push_back(token.substr(start, end - start));

		if (userData[0] == "2")
		{
			int userID = stoi(userData[1]);

			Administrator admin(userID, userData[2], userData[3], administrator);
			users.push_back(admin);
		}
		else if (userData[0] == "1")
		{
			int userID = stoi(userData[1]);

			Client individ(userID, userData[2], userData[3], client);
			users.push_back(individ);
		}
		else
		{
			cout << "Invalid user type" << endl;
		}

	}
	return users;
}

vector<string> readUserData(void)
{
	vector<string> userData;
	string username;
	string password;
	cout << "Username: ";
	cin >> username;
	cout << "Password: ";
	cin >> password;
	userData.push_back(username);
	userData.push_back(password);
	return userData;
}