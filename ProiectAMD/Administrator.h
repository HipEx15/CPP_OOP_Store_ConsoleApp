#pragma once

#include <vector>
#include <string>
#include "User.h"
#include "FinalObjects.h"
#include "Client.h"

using namespace std;

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

void removeItem(std::string Name, std::string filePath);
void addItem(std::vector<Inventory*>& inventory, std::string filepath);
bool memberExists(std::string username, vector<User> users);
void modifyRoleType(std::string username, vector<User>& users, roleType role);
bool updateFile(vector<User> users);

void printInventory(std::vector<Inventory*> inventory);