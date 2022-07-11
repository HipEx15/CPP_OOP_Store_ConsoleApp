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

void removeItem(std::vector<Inventory*>& inventory, std::string Name, std::string filePath)
{
	std::ifstream inFile;
	inFile.open(filePath);
	std::string line;
	std::string newLine;
	while(getline(inFile, line))
	{
		if(line.find(Name) == std::string::npos)
		{
			newLine += line + "\n";
		}
	}
	inFile.close();
	std::ofstream outFile;
	outFile.open(filePath);
	outFile << newLine;
	outFile.close();
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

		cin >> cores;
		cout << "Threads: ";
		cin >> threads;
		cout << "Socket: ";
		cin >> socket;

		Dir.setBuilder(&BC);
		C = Dir.getFC(weight, height, tdp, nms, memory, frequency, priceTag, name, date, cores, threads, socket);
		inventory.push_back(C);
		file << "CPU" << " " << weight << " " << height << " " << tdp << " " << nms << " " << memory << " " << frequency << " " << cores << " " << threads << " " << socket << " " << priceTag << " " << name << " " << date << endl;
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
		cout << "PriceTag: ";
		cin >> priceTag;
		cout << "Name: ";
		cin >> name;
		cout << "Date: ";
		cin >> date;
		
		cout << "Resolution: ";
		cin >> vers;
		cout << "Version: ";
		if (vers == 1)
		{
			Dir.setBuilder(&BG);
			G = Dir.getFG(weight, height, tdp, nms, memory, frequency, priceTag, name, date, resolution, OpenGL);
			inventory.push_back(G);
			file << "GPU" << " " << weight << " " << height << " " << tdp << " " << nms << " " << memory << " " << frequency << " " << priceTag << " " << name << " " << date << " " << resolution << " " << OpenGL << endl;
			file.close();
		}
		else if (vers == 2)
		{
			Dir.setBuilder(&BG);
			G = Dir.getFG(weight, height, tdp, nms, memory, frequency, priceTag, name, date, resolution, DirectX);
			inventory.push_back(G);
			file << "GPU" << " " << weight << " " << height << " " << tdp << " " << nms << " " << memory << " " << frequency << " " << priceTag << " " << name << " " << date << " " << resolution << " " << OpenGL << endl;
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
		cout << "Frequency: ";
		cin >> frequency;
		cout << "PriceTag: ";
		cin >> priceTag;
		cout << "Name: ";
		cin >> name;
		cout << "Date: ";
		cin >> date;

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
			A = Dir.getFA(weight, height, tdp, nms, memory, frequency, priceTag, name, date, cores, threads, socket, resolution, OpenGL);
			inventory.push_back(A);
			file << "ALU" << " " << weight << " " << height << " " << tdp << " " << nms << " " << memory << " " << frequency << " " << priceTag << " " << name << " " << date << " " << cores << " " << threads << " " << socket << " " << resolution << " " << OpenGL << endl;
			file.close();
		}
		else if (vers == 2)
		{
			Dir.setBuilder(&BA);
			A = Dir.getFA(weight, height, tdp, nms, memory, frequency, priceTag, name, date, cores, threads, socket, resolution, OpenGL);
			inventory.push_back(A);
			file << "ALU" << " " << weight << " " << height << " " << tdp << " " << nms << " " << memory << " " << frequency << " " << priceTag << " " << name << " " << date << " " << cores << " " << threads << " " << socket << " " << resolution << " " << OpenGL << endl;
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