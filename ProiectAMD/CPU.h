#pragma once

#include <iostream>
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
	void PrintC(void);

	//Getters
	unsigned short int GetCores(void);
	unsigned short int GetThreads(void);
	std::string GetSocket(void);
};