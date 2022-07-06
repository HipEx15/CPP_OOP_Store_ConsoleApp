#include "CPU.h"

CPU::CPU(void)
{
	this->cores = 0;
	this->threads = 0;
	this->socket = "?";
}

CPU::CPU(unsigned short int cores, unsigned short int threads, std::string socket)
{
	this->cores = cores;
	this->threads = threads;
	this->socket = socket;
}

