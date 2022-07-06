#pragma once

#include "Products.h"
#include "CPU.h"
#include "GPU.h"
#include "APU.h"

class FinalProduct
{
public:
	Products* p;
	void PrintProd(void)
	{
		std::cout << "\n    PRODUCT: ";
		p->PrintP();
	}
};

class FinalCPU
{
public:
	Products* p;
	CPU* c;
	void PrintC(void)
	{
		std::cout << "\n    CPU: ";
		p->PrintP();
		c->PrintC();
	}
};

class FinalGPU
{
public:
	Products* p;
	GPU* g;
	void PrintG(void)
	{
		std::cout << "\n    GPU: ";
		p->PrintP();
		g->PrintG();
	}
};

class FinalAPU
{
public:
	Products* p;
	CPU* c;
	GPU* g;
	void PrintA(void)
	{
		std::cout << "\n    APU: ";
		p->PrintP();
		c->PrintC();
		g->PrintG();
	}
};