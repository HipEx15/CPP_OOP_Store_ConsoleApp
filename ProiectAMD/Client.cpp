#include "Client.h"

Client::Client(void) : User()
{}

Client::Client(std::string username, std::string password, roleType role) : User(username, password, role)
{}

void Client::setRole(roleType role)
{
	this->role = role;
}

void Client::addItem(Inventory* i, std::vector<Inventory*> inventory)
{
	bool ok = false;
	for (auto j : inventory)
	{
		if (i == j)
		{
			ok = true;
			break;
		}
	}
	
	if (ok)
		this->basket.push_back(i);
	else
		std::cout << "\Nu avem pe stoc.";
	
}

void Client::removeItem(Inventory* i)
{
	unsigned short int index = 0;
	for (auto j : this->basket)
	{
		if (j == i)
			break;
		else
			index++;
	}

	std::cout << "\nINDEX: " << index;
	this->basket.erase(this->basket.begin() + index);
}

void Client::printBasket(void)
{
	for (auto i : this->basket)
		i->Print();
}

int Client::getNumberId(void)
{
	return this->numberID;
}

std::string Client::getUsername(void)
{
	return this->username;
}

std::string Client::getPassword(void)
{
	return this->password;
}

roleType Client::getRole(void)
{
	return this->role;
}