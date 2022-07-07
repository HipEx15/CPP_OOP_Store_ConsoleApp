#include "User.h"

User::User(void)
{
	this->username = "?";
	this->password = "?";
	this->role = Client;
}

User::User(std::string username, std::string password, roleType role)
{
	this->ID += 1;
	this->username = username;
	this->password = password;
	this->role = role;
}