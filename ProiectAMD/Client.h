#pragma once

#include <vector>
#include <string>
#include <iostream>

using namespace std;

#include "User.h"
#include "Administrator.h"
#include "FinalObjects.h"

enum Type {cpu, gpu, apu};

class Client : public User
{
private:
	vector<Inventory*> basket;

public:
	Client(void);
	Client(int ID, std::string username, std::string password, roleType role);

	void setRole(roleType role);
	void addItem(std::string fileName, std::string newFileName, std::string Name);
	void removeItem(std::string Name, std::string filePath);

	void printBasket(void);

	int getNumberId(void);
	std::string getUsername(void);
	std::string getPassword(void);
	roleType getRole(void);
	void setBasket(vector<Inventory*> basket);

	std::vector<Inventory*> getBasket(void);
};

Type whichType(void);
std::vector<Inventory*> ReadBasket(std::string filepath, std::string del);