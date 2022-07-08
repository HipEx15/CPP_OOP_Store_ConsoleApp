#include "User.h"

User::User(void)
{
	this->numberID = 0;
	this->username = "?";
	this->password = "?";
	this->role = Client;
}

User::User(std::string username, std::string password, roleType role)
{
	this->numberID +=1 ;
	this->username = username;
	this->password = password;
	this->role = role;
}