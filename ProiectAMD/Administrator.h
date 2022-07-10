#pragma once

#include <vector>
#include "User.h"
#include "FinalObjects.h"
#include "Client.h"

class Administrator : public User
{
private:
	std::vector<Inventory*> inventory;

public:
	Administrator(void);
	Administrator(std::string username, std::string password, roleType role);
	void addItem(Inventory* i);
	void removeItem(Inventory* i);
	//void changeroleType(Client C);
	void printInventory(void);
	std::vector<Inventory*> getInventory(void);

	int getNumberId(void);
	std::string getUsername(void);
	std::string getPassword(void);
	roleType getRole(void);
};