#pragma once

#include <vector>
#include "User.h"
#include "Administrator.h"
#include "Client.h"

using namespace std;

void Menu(void);

void LoginMenu(void);
void LoginAdminMenu(void);
void LoginClientMenu(void);

void LogInClient(void);

void RegisterMenu(void);
void RegisterAdminMenu(void);
void RegisterAdmin(vector<User>& admins);

void RegisterClientMenu(void);
void RegisterClient(vector<User>& clients);

vector<string> readFile(string fileName);
vector<User> tokenize(string filepath, string del);
vector<string> readUserData(void);