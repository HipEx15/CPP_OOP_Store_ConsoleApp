#include "Administrator.h"

Administrator::Administrator(void) : User()
{}

Administrator::Administrator(std::string username, std::string password, roleType role) : User(username, password, role)
{}