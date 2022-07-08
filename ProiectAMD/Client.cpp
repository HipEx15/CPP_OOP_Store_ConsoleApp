#include "Client.h"

Client::Client(void) : User()
{}

Client::Client(std::string username, std::string password, roleType role) : User(username, password, role)
{}

void Client::setRole(roleType role)
{
	this->role = role;
}
