#include "Administrator.h"

Administrator::Administrator(void) : User()
{}

Administrator::Administrator(std::string username, std::string password, roleType role) : User(username, password, role)
{}

void Administrator::addItem(Inventory* i)
{
	this->inventory.push_back(i);
}

void Administrator::removeItem(Inventory* i)
{
	unsigned short int index = 0;
	for (auto j : this->inventory)
	{
		if (j == i)
			break;
		else
			index++;
	}

	std::cout << "\nINDEX: " << index;
	this->inventory.erase(this->inventory.begin() + index);
}


std::vector<Inventory*> Administrator::getInventory(void)
{
	return this->inventory;
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

void Administrator::printInventory(void)
{
	for (auto i : this->inventory)
		i->Print();
}
