#include <iostream>
#include <fstream>
#include <string>

#include "Administrator.h"
#include "Builder.h"
#include "Director.h"
#include "Menus.h"

using namespace std;

Administrator::Administrator(void) : User()
{}

Administrator::Administrator(int ID, std::string username, std::string password, roleType role) : User(username, password, role, ID)
{}

void removeItem(std::string Name, std::string filePath)
{
	string line;
	fstream fin;
	fstream fout;
	fin.open(filePath, ios::in);
	fout.open("Temp.txt", ios::out | ios::app);

	vector<string> lines;
	while (getline(fin, line)) 
	{
		if (line.find(Name) == string::npos) 
			fout << line << endl;
		
	}
	fout.close();
	fin.close();

	remove("Inventory.txt");
	rename("Temp.txt", "Inventory.txt");
}

void addItem(std::vector<Inventory*>& inventory, std::string filepath)
{
	string type;

	std::ofstream file;
	file.open("Inventory.txt", fstream::app);

	FinalCPU* C;
	FinalGPU* G;
	FinalAPU* A;

	BuildCPU BC;
	BuildGPU BG;
	BuildAPU BA;

	Director Dir;

	float weight;
	float height;
	unsigned short int tdp;
	unsigned short int nms;
	unsigned short int memory;
	float frequency;
	float priceTag;
	std::string name;
	std::string date;

	unsigned short int cores;
	unsigned short int threads;
	string socket;

	string resolution;
	unsigned short int vers;

	cout << "Item type: ";
	cin >> type;
	if (type == "CPU")
	{
		cout << "Weight: ";
		cin >> weight;
		cout << "Height: ";
		cin >> height;
		cout << "TDP: ";
		cin >> tdp;
		cout << "NMS: ";
		cin >> nms;
		cout << "Memory: ";
		cin >> memory;
		cout << "Frequency: ";
		cin >> frequency;
		cout << "PriceTag: ";
		cin >> priceTag;
		cout << "Name: ";
		cin >> name;
		cout << "Date: ";
		cin >> date;

		cout << "Cores: ";
		cin >> cores;
		cout << "Threads: ";
		cin >> threads;
		cout << "Socket: ";
		cin >> socket;

		Dir.setBuilder(&BC);
		C = Dir.getFC(weight, height, tdp, nms, memory, frequency, priceTag, name, date, cores, threads, socket);
		inventory.push_back(C);
		file << "CPU" << " " << weight << " " << height << " " << tdp << " " << nms << " " << memory << " " << frequency << " " << cores << " " << threads << " " << socket << " " << priceTag << " " << name << " " << date << endl;
	}
	else if (type == "GPU")
	{
		cout << "Weight: ";
		cin >> weight;
		cout << "Height: ";
		cin >> height;
		cout << "TDP: ";
		cin >> tdp;
		cout << "NMS: ";
		cin >> nms;
		cout << "Memory: ";
		cin >> memory;
		cout << "Frequency: ";
		cin >> frequency;
		cout << "PriceTag: ";
		cin >> priceTag;
		cout << "Name: ";
		cin >> name;
		cout << "Date: ";
		cin >> date;
		
		cout << "Resolution: ";
		cin >> resolution;
		cout << "Version: ";
		cin >> vers;
		if (vers == 1)
		{
			Dir.setBuilder(&BG);
			G = Dir.getFG(weight, height, tdp, nms, memory, frequency, priceTag, name, date, resolution, OpenGL);
			inventory.push_back(G);
			file << "GPU" << " " << weight << " " << height << " " << tdp << " " << nms << " " << memory << " " << frequency << " " << priceTag << " " << name << " " << date << " " << resolution << " " << OpenGL << endl;
		}
		else if (vers == 2)
		{
			Dir.setBuilder(&BG);
			G = Dir.getFG(weight, height, tdp, nms, memory, frequency, priceTag, name, date, resolution, DirectX);
			inventory.push_back(G);
			file << "GPU" << " " << weight << " " << height << " " << tdp << " " << nms << " " << memory << " " << frequency << " " << priceTag << " " << name << " " << date << " " << resolution << " " << OpenGL << endl;

		}
	}
	else if (type == "APU")
	{
		cout << "Weight: ";
		cin >> weight;
		cout << "Height: ";
		cin >> height;
		cout << "TDP: ";
		cin >> tdp;
		cout << "NMS: ";
		cin >> nms;
		cout << "Memory: ";
		cin >> memory;
		cout << "Frequency: ";
		cin >> frequency;
		cout << "PriceTag: ";
		cin >> priceTag;
		cout << "Name: ";
		cin >> name;
		cout << "Date: ";
		cin >> date;

		cout << "Cores: ";
		cin >> cores;
		cout << "Threads: ";
		cin >> threads;
		cout << "Socket: ";
		cin >> socket;

		cout << "Resolution: ";
		cin >> resolution;
		cout << "Version: ";
		cin >> vers;
		if (vers == 1)
		{
			Dir.setBuilder(&BA);
			A = Dir.getFA(weight, height, tdp, nms, memory, frequency, priceTag, name, date, cores, threads, socket, resolution, OpenGL);
			inventory.push_back(A);
			file << "APU" << " " << weight << " " << height << " " << tdp << " " << nms << " " << memory << " " << frequency << " " << priceTag << " " << name << " " << date << " " << cores << " " << threads << " " << socket << " " << resolution << " " << OpenGL << endl;
		}
		else if (vers == 2)
		{
			Dir.setBuilder(&BA);
			A = Dir.getFA(weight, height, tdp, nms, memory, frequency, priceTag, name, date, cores, threads, socket, resolution, OpenGL);
			inventory.push_back(A);
			file << "APU" << " " << weight << " " << height << " " << tdp << " " << nms << " " << memory << " " << frequency << " " << priceTag << " " << name << " " << date << " " << cores << " " << threads << " " << socket << " " << resolution << " " << OpenGL << endl;
		}
		
	}
	file.close();
}

void printInventory(std::vector<Inventory*> inventory)
{
	for (auto i : inventory)
		i->Print();
}

int Administrator::getNumberId(void)
{
	return this->numberID;
}

std::string Administrator::getUsername(void)
{
	return this->username;
}

std::string Administrator::getPassword(void)
{
	return this->password;
}

roleType Administrator::getRole(void)
{
	return this->role;
}

bool memberExists(std::string username, vector<User> users)
{
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].getUsername() == username)
		{
			return true;
		}
	}
	return false;
}

void modifyRoleType(std::string username, vector<User>& users, roleType role)
{
	if (memberExists(username, users))
	{
		for (int i = 0; i < users.size(); i++)
		{
			if (users[i].getUsername() == username)
			{
				users[i].setRole(role);
			}
		}

		updateFile(users);
	}
}

bool updateFile(vector<User> users) {
	ofstream file;
	file.open("Register.txt");
	for (int i = 0; i < users.size(); i++)
	{
		file << users[i].getRole() << " " << users[i].getID() << " " << users[i].getUsername() << " " << users[i].getPassword() << endl;
	}
	file.close();

	return true;
}