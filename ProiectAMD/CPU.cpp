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

void CPU::PrintC(void)
{
	std::cout <<"\n\tCores: " << this->GetCores() << "\n\tThreads: " << this->GetThreads() << "\n\tSocket: " << this->GetSocket();
}

unsigned short int CPU::GetCores(void)
{
	return this->cores;
}

unsigned short int CPU::GetThreads(void)
{
	return this->threads;
}

std::string CPU::GetSocket(void)
{
	return this->socket;
}
