#pragma once

#include <vector>
#include "User.h"
#include "Administrator.h"
#include "Client.h"

void Menu(void);

void LoginMenu(void);
void LoginAdminMenu(void);
void LoginClientMenu(void);

void LogInClient(void);

void RegisterMenu(void);
void RegisterAdminMenu(void);
void RegisterAdmin(std::vector<Administrator>& admins);

void RegisterClientMenu(void);
void RegisterClient(std::vector<Client>& clients);