#pragma once

#include <string>
#include "Products.h"

class CPU : virtual public Products
{
protected:
	unsigned short int cores;
	unsigned short int threads;
	std::string socket;

};