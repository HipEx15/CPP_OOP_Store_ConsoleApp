#include <iostream>
#include <fstream>
#include <string>

#include "Administrator.h"
#include "Builder.h"
#include "Director.h"

using namespace std;

Administrator::Administrator(void) : User()
{}

Administrator::Administrator(int ID, std::string username, std::string password, roleType role) : User(username, password, role, ID)
{}

void removeItem(std::vector<Inventory*> inventory, Inventory* i)
{
	unsigned short int index = 0;
	for (auto j : inventory)
	{
		if (j == i)
			break;
		else
			index++;
	}

	std::cout << "\nINDEX: " << index;
	inventory.erase(inventory.begin() + index);
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
		cout << "Cores: ";

		cin >> cores;
		cout << "Threads: ";
		cin >> threads;
		cout << "Socket: ";
		cin >> socket;

		Dir.setBuilder(&BC);
		C = Dir.getFC(weight, height, tdp, nms, memory, frequency, cores, threads, socket);
		inventory.push_back(C);
		file << "CPU" << " " << weight << " " << height << " " << tdp << " " << nms << " " << memory << " " << frequency << " " << cores << " " << threads << " " << socket << endl;
		file.close();
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
		cout << "Resolution: ";
		cin >> vers;
		cout << "Version: ";
		if (vers == 1)
		{
			Dir.setBuilder(&BG);
			G = Dir.getFG(weight, height, tdp, nms, memory, frequency, resolution, OpenGL);
			inventory.push_back(G);
			file << "GPU" << " " << weight << " " << height << " " << tdp << " " << nms << " " << memory << " " << frequency << " " << resolution << " " << OpenGL << endl;
			file.close();
		}
		else if (vers == 2)
		{
			Dir.setBuilder(&BG);
			G = Dir.getFG(weight, height, tdp, nms, memory, frequency, resolution, DirectX);
			inventory.push_back(G);
			file << "GPU" << " " << weight << " " << height << " " << tdp << " " << nms << " " << memory << " " << frequency << " " << resolution << " " << OpenGL << endl;
			file.close();

		}
	}
	else if (type == "ALU")
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

		cin >> cores;
		cout << "Threads: ";
		cin >> threads;
		cout << "Socket: ";
		cin >> socket;

		cout << "Frequency: ";
		cin >> frequency;
		cout << "Resolution: ";
		cin >> vers;
		cout << "Version: ";
		if (vers == 1)
		{
			Dir.setBuilder(&BA);
			A = Dir.getFA(weight, height, tdp, nms, memory, frequency, cores, threads, socket, resolution, OpenGL);
			inventory.push_back(A);
			file << "ALU" << " " << weight << " " << height << " " << tdp << " " << nms << " " << memory << " " << frequency << " " << cores << " " << threads << " " << socket << " " << resolution << " " << OpenGL << endl;
			file.close();
		}
		else if (vers == 2)
		{
			Dir.setBuilder(&BA);
			A = Dir.getFA(weight, height, tdp, nms, memory, frequency, cores, threads, socket, resolution, OpenGL);
			inventory.push_back(A);
			file << "ALU" << " " << weight << " " << height << " " << tdp << " " << nms << " " << memory << " " << frequency << " " << cores << " " << threads << " " << socket << " " << resolution << " " << OpenGL << endl;
			file.close();
		}
	}
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


/*
void Administrator::changeroleType(Client C)
{
	C.setRole(administrator);
}*/