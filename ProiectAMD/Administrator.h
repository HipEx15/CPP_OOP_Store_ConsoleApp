#pragma once

#include "User.h"
#include "FinalObjects.h"

class Administrator : public User
{
public:
	Administrator(void);
	Administrator(std::string username, std::string password, roleType role);
};