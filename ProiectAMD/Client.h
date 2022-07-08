#pragma once

#include <vector>
#include "User.h"
#include "Administrator.h"
#include "FinalObjects.h"

class Client : public User
{
private:
	std::vector<Inventory*> basket;

public:
	Client(void);
	Client(std::string username, std::string password, roleType role);
	void setRole(roleType role);
	void addItem(Inventory* i, std::vector<Inventory*> inventory);
	void removeItem(Inventory* i);
	void printBasket(void);
};