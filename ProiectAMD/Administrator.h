#pragma once

#include <vector>
#include "User.h"
#include "FinalObjects.h"
#include "Client.h"

class Administrator : public User
{
public:
	Administrator(void);
	Administrator(int ID, std::string username, std::string password, roleType role);

	//void changeroleType(Client C);

	int getNumberId(void);
	std::string getUsername(void);
	std::string getPassword(void);
	roleType getRole(void);
};

void addItem(std::vector<Inventory*> inventory, Inventory* i);
void removeItem(std::vector<Inventory*> inventory, Inventory* i);
void printInventory(std::vector<Inventory*> inventory);