#pragma once

#include <vector>
#include <string>
#include "User.h"
#include "FinalObjects.h"
#include "Client.h"
#include <string>
#include <iostream>

class Administrator : public User
{
public:
	Administrator(void);
	Administrator(int ID, std::string username, std::string password, roleType role);

	void removeItem(std::string Name, std::string filePath);
	void addItem(std::vector<Inventory*>& inventory, std::string filepath);
	void modifyRoleType(std::string username, vector<User>& users, roleType role);

	int getNumberId(void);
	std::string getUsername(void);
	std::string getPassword(void);
	roleType getRole(void);
};


bool memberExists(std::string username, vector<User> users);
bool updateFile(vector<User> users);

void printInventory(std::vector<Inventory*> inventory);