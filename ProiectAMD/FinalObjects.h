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