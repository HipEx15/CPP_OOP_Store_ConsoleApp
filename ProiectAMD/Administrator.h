#pragma once

#include "Builder.h"
#include "FinalObjects.h"
#include "User.h"
#include <vector>

class Admin : public User
{
private:
	Builder* builder;
	std::vector<Inventory*> inventory;

public:
	Admin(void) {};
	Admin(Builder* builder);
	void setBuilder(Builder* builder);
	FinalProduct* getFP(float weight, float height, unsigned short int tdp, unsigned short int nms, unsigned short int memory, float frequency);
	FinalCPU* getFC(float weight, float height, unsigned short int tdp, unsigned short int nms, unsigned short int memory, float frequency, unsigned short int cores, unsigned short int threads, std::string socket);
	FinalGPU* getFG(float weight, float height, unsigned short int tdp, unsigned short int nms, unsigned short int memory, float frequency, std::string maximumResolution, version differentVersions);
	FinalAPU* getFA(float weight, float height, unsigned short int tdp, unsigned short int nms, unsigned short int memory, float frequency, unsigned short int cores, unsigned short int threads, std::string socket, std::string maximumResolution, version differentVersions);
	void addProduct(Inventory* Inv);
	void printAllProducts(void);
	std::vector<Inventory*> getInventory(void);
};