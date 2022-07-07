#include "Administrator.h"

Admin::Admin(Builder* builder)
{
	this->builder = builder;
}

void Admin::setBuilder(Builder* builder)
{
	this->builder = builder;
}

FinalProduct* Admin::getFP(float weight, float height, unsigned short int tdp, unsigned short int nms, unsigned short int memory, float frequency)
{
	FinalProduct* FP = new FinalProduct();

	FP->p = builder->product(weight,height,tdp,nms,memory,frequency);

	return FP;
}

FinalCPU* Admin::getFC(float weight, float height, unsigned short int tdp, unsigned short int nms, unsigned short int memory, float frequency, unsigned short int cores, unsigned short int threads, std::string socket)
{
	FinalCPU* FC = new FinalCPU();

	FC->p = builder->product(weight, height, tdp, nms, memory, frequency);
	FC->c = builder->cpu(cores, threads, socket);

	return FC;
}

FinalGPU* Admin::getFG(float weight, float height, unsigned short int tdp, unsigned short int nms, unsigned short int memory, float frequency, std::string maximumResolution, version differentVersions)
{
	FinalGPU* FG = new FinalGPU();

	FG->p = builder->product(weight, height, tdp, nms, memory, frequency);
	FG->g = builder->gpu(maximumResolution, differentVersions);

	return FG;
}

FinalAPU* Admin::getFA(float weight, float height, unsigned short int tdp, unsigned short int nms, unsigned short int memory, float frequency, unsigned short int cores, unsigned short int threads, std::string socket, std::string maximumResolution, version differentVersions)
{
	FinalAPU* FA = new FinalAPU();

	FA->p = builder->product(weight, height, tdp, nms, memory, frequency);
	FA->c = builder->cpu(cores, threads, socket);
	FA->g = builder->gpu(maximumResolution, differentVersions);

	return FA;
}

void Admin::addProduct(Inventory* Inv)
{
	this->inventory.push_back(Inv);
}

void Admin::printAllProducts(void)
{
	for (auto i : this->inventory)
		i->Print();
}

std::vector<Inventory*> Admin::getInventory(void)
{
	return this->inventory;
}
