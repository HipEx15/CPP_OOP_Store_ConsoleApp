#pragma once

#include <string>

enum roleType{Client=1, Administrator };

class User
{
private:
	static int ID;
	std::string username;
	std::string password;
	roleType role;

public:
	User(void);
	User(std::string username, std::string password, roleType role);
};