#include <iostream>
#include "User.h"

User::User(void)
{
	this->numberID = 0;
	this->username = "?";
	this->password = "?";
	this->role = client;
}

User::User(std::string username, std::string password, roleType role, int ID)
{
	this->numberID = ID;
	this->username = username;
	this->password = password;
	this->role = role;
}

void User::print(void) {
	std::cout << "User: " << this->username << " " << this->password << " " << this->role << " " << this->numberID << std::endl;
}

//getters
int User::getID(void) {
	return this->numberID;
}
std::string User::getUsername(void) {
	return this->username;
}
std::string User::getPassword(void) {
	return this->password;
}
roleType User::getRole(void) {
	return this->role;
}