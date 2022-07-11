#pragma once

#include <vector>
#include "User.h"
#include "Administrator.h"
#include "Client.h"

using namespace std;

void Menu(void);

void LoginMenu(void);

void RegisterMenu(void);
void RegisterAdminMenu(void);
void RegisterMenuEmpty(void);
void RegisterClientMenu(void);

void ClientMenu(void);
void AdminMenu(void);

vector<string> readFile(string fileName);
vector<User> tokenize(string filepath, string del);
vector<string> readUserData(void);