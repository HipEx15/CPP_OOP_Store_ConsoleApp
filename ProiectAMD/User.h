#pragma once

#include <string>

enum roleType { client = 1, administrator};

class User
{
protected:
	int numberID;
	std::string username;
	std::string password;
	roleType role;

public:
	User(void);
	User(std::string username, std::string password, roleType role);
	User(std::string username, std::string password, roleType role, int ID);

	void print(void);
	int getID(void);
	std::string getUsername(void);
	std::string getPassword(void);
	roleType getRole(void);
};