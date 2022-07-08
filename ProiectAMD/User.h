#pragma once

#include <string>

enum roleType { client = 1, administrator};

class User
{
protected:
	static int numberID;
	std::string username;
	std::string password;
	roleType role;

public:
	User(void);
	User(std::string username, std::string password, roleType role);
};