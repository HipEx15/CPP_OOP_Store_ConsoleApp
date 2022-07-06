#include "Products.h"

Products::Products(void)
{
	this->weight = 0;
	this->height = 0;
	this->tdp = 0;
	this->nms = 0;
	this->memory = 0;
	this->frequency = 0;
}

Products::Products(float weight, float height, unsigned short int tdp, unsigned short int nms, unsigned short int memory, float frequency)
{
	this->weight = weight;
	this->height = height;
	this->tdp = tdp;
	this->nms = nms;
	this->memory = memory;
	this->frequency = frequency;
}

void Products::PrintP(void)
{
	std::cout << "\n\tWeight: "<< this->weight << "\n\tHeight: " << this->height << "\n\tTDP: " << this->tdp << "\n\tNMS: " << this->nms << "\n\tMemory:" << this->memory << "\n\tFrequency: " << this->frequency;
}
