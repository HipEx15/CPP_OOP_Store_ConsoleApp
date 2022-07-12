#pragma once

#include "Products.h"
#include "CPU.h"
#include "GPU.h"
#include "APU.h"

class Inventory
{
public:
	virtual void Print(void) {};
	virtual Products* getProduct() { return NULL; };
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

	Products* getProduct()
	{
		return p;
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

	Products* getProduct()
	{
		return p;
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
	Products* getProduct()
	{
		return p;
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
	Products* getProduct()
	{
		return p;
	}
};