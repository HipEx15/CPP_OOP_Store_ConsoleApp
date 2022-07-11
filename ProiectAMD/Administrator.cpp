#include "Administrator.h"

Administrator::Administrator(void) : User()
{}

Administrator::Administrator(int ID, std::string username, std::string password, roleType role) : User(username, password, role, ID)
{}

void addItem(std::vector<Inventory*> inventory, Inventory* i)
{
	inventory.push_back(i);
}

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