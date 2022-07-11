#pragma once

#include <iostream>

class Products
{
protected:
	float weight;
	float height;
	unsigned short int tdp;
	unsigned short int nms;
	unsigned short int memory;
	float frequency;

public:
	Products(void);
	Products(float weight, float height, unsigned short int tdp, unsigned short int nms, unsigned short int memory, float frequency);
	void PrintP(void);

	//Getters
	float GetWeight(void);
	float GetHeight(void);
	unsigned short int GetTDP(void);
	unsigned short int GetNMS(void);
	unsigned short int GetMemory(void);
	float GetFrequency(void);
};