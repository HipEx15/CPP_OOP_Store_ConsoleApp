#pragma once

#include "Products.h"
#include "CPU.h"
#include "GPU.h"
#include "APU.h"

class FinalProduct
{
public:
	Products* p;
};

class FinalCPU
{
public:
	Products* p;
	CPU* c;
	void PrintC(void)
	{
		std::cout << "\nCPU: ";
		//std::cout << "\nCPU: " << c->cores << " " << c->threads << " " << c->socket << "\n";
		p->PrintP();
		c->PrintC();
	}
};

class FinalGPU
{
public:
	Products* p;
	GPU* g;
};

class FinalAPU
{
public:
	Products* p;
	CPU* c;
	GPU* g;
};