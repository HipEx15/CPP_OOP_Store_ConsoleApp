#pragma once

#include "Products.h"
#include "CPU.h"
#include "GPU.h"
#include "APU.h"

class Inventory
{
public:
	virtual void Print(void) {};
};

class FinalProduct : public Inventory
{
public:
	Products* p;
	void Print(void)
	{
		std::cout << "\n    PRODUCT: ";
		p->PrintP();
	}
};

class FinalCPU : public Inventory
{
public:
	Products* p;
	CPU* c;
	void Print(void)
	{
		std::cout << "\n    CPU: ";
		p->PrintP();
		c->PrintC();
	}
};

class FinalGPU : public Inventory
{
public:
	Products* p;
	GPU* g;
	void Print(void)
	{
		std::cout << "\n    GPU: ";
		p->PrintP();
		g->PrintG();
	}
};

class FinalAPU : public Inventory
{
public:
	Products* p;
	CPU* c;
	GPU* g;
	void Print(void)
	{
		std::cout << "\n    APU: ";
		p->PrintP();
		c->PrintC();
		g->PrintG();
	}
};