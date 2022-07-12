#include <iostream>
#include <string>
#include <fstream>
#include "Menus.h"
#include "Builder.h"
#include "Director.h"

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
	std::cout << "\n 0 - Log out";
	std::cout << "\n 1 - Add product to basket";
	std::cout << "\n 2 - Remove product from basket";
	std::cout << "\n 3 - Print basket";
	std::cout << "\n 4 - Print inventory";
	std::cout << "\n 5 - Print by filter";
	std::cout << "\n 6 - Checkout";
	std::cout << "\n 9 - Exit";
	cout << "\nOption: ";
}

void FiltersMenu(void)
{
	std::cout << "\n\t---AMD SHOP---\n\t";
	std::cout << "\nClient menu: ";
	std::cout << "\n 0 - Log out";
	std::cout << "\n 1 - Sort by name (asc)";
	std::cout << "\n 2 - Sort by name (desc)";
	std::cout << "\n 3 - Sort by release date (asc)";
	std::cout << "\n 4 - Sort by release date (desc)";
	std::cout << "\n 5 - Sort by price (asc)";
	std::cout << "\n 6 - Sort by price (desc)";

	std::cout << "\n 8 - Back";
	std::cout << "\n 9 - Exit";
	cout << "\nOption: ";
}

void AdminMenu(void)
{
	std::cout << "\n\t---AMD SHOP---\n\t";
	std::cout << "\nAdministrator menu: \n";
	std::cout << "\n 0 - Log out";
	std::cout << "\n 1 - Add product to inventory";
	std::cout << "\n 2 - Remove product to inventory";
	std::cout << "\n 3 - Add admin";
	std::cout << "\n 4 - Print inventory";
	std::cout << "\n 9 - Exit";
	cout << "\nOption: ";
}

vector<Inventory*> ReadInventory(string filepath, string del)
{
	vector<string> tokens = readFile(filepath);

	vector<Inventory*> inventory;

	for (string token : tokens)
	{
		FinalCPU* C;
		FinalGPU* G;
		FinalAPU* A;

		BuildCPU BC;
		BuildGPU BG;
		BuildAPU BA;

		Director Dir;

		vector<string> items;

		int start = 0;
		int end = token.find(del);
		while (end != -1)
		{
			items.push_back(token.substr(start, end - start));
			start = end + del.size();
			end = token.find(del, start);
		}

		items.push_back(token.substr(start, end - start));

		if (items[0] == "CPU")
		{
			float weight = stof(items[1]);
			float height = stof(items[2]);
			unsigned short int tdp = stoi(items[3]);
			unsigned short int nms = stoi(items[4]);
			unsigned short int memory = stoi(items[5]);
			float frequency = stof(items[6]);
			float priceTag = stof(items[7]);
			string name = items[8];
			string date = items[9];

			unsigned short int cores = stoi(items[10]);
			unsigned short int threads = stoi(items[11]);
			string socket = items[12];

			Dir.setBuilder(&BC);
			C = Dir.getFC(weight, height, tdp, nms, memory, frequency, priceTag, name, date, cores, threads, socket);
			inventory.push_back(C);
		}
		else if (items[0] == "GPU")
		{
			float weight = stof(items[1]);
			float height = stof(items[2]);
			unsigned short int tdp = stoi(items[3]);
			unsigned short int nms = stoi(items[4]);
			unsigned short int memory = stoi(items[5]);
			float frequency = stof(items[6]);
			float priceTag = stof(items[7]);
			string name = items[8];
			string date = items[9];
			string resolution = items[10];
			if (items[11] == "1")
			{
				Dir.setBuilder(&BG);
				G = Dir.getFG(weight, height, tdp, nms, memory, frequency, priceTag, name, date, resolution, OpenGL);
				inventory.push_back(G);
			}
			else if (items[11] == "2")
			{
				Dir.setBuilder(&BG);
				G = Dir.getFG(weight, height, tdp, nms, memory, frequency, priceTag, name, date, resolution, DirectX);
				inventory.push_back(G);
			}
		}
		else if (items[0] == "APU")
		{
			float weight = stof(items[1]);
			float height = stof(items[2]);
			unsigned short int tdp = stoi(items[3]);
			unsigned short int nms = stoi(items[4]);
			unsigned short int memory = stoi(items[5]);
			float frequency = stof(items[6]);
			float priceTag = stof(items[7]);
			string name = items[8];
			string date = items[9];

			unsigned short int cores = stoi(items[10]);
			unsigned short int threads = stoi(items[11]);
			string socket = items[12];

			string resolution = items[13];
			if (items[14] == "1")
			{
				Dir.setBuilder(&BA);
				A = Dir.getFA(weight, height, tdp, nms, memory, frequency, priceTag, name, date, cores, threads, socket, resolution, OpenGL);
				inventory.push_back(A);
			}
			else if (items[14] == "2")
			{
				Dir.setBuilder(&BA);
				A = Dir.getFA(weight, height, tdp, nms, memory, frequency, priceTag, name, date, cores, threads, socket, resolution, OpenGL);
				inventory.push_back(A);
			}
		}
		else
		{
			cout << "Invalid items type" << endl;
		}
	}
	return inventory;
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

vector<User> initiateMembers(string filepath, string del)
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