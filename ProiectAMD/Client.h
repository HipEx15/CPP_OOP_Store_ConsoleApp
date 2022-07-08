#pragma once

#include "User.h"

class Client : public User
{
public:
	Client(void);
	Client(std::string username, std::string password, roleType role);
};