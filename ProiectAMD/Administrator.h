#pragma once

#include <vector>
#include <string>
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

void removeItem(std::vector<Inventory*> inventory, Inventory* i);
void addItem(std::vector<Inventory*>& inventory, std::string filepath);
void printInventory(std::vector<Inventory*> inventory);