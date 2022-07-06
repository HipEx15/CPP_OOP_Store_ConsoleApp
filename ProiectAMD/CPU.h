#pragma once

#include <string>
#include "Products.h"

class CPU
{
protected:
	unsigned short int cores;
	unsigned short int threads;
	std::string socket;

public:
	CPU(void);
	CPU(unsigned short int cores, unsigned short int threads, std::string socket);
};