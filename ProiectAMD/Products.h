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
	
	float priceTag;
	std::string name;
	std::string date;

public:
	Products(void);
	Products(float weight, float height, unsigned short int tdp, unsigned short int nms, unsigned short int memory, float frequency, float priceTag, std::string Name, std::string Date);
	void PrintP(void);

	//Getters
	float GetWeight(void);
	float GetHeight(void);
	unsigned short int GetTDP(void);
	unsigned short int GetNMS(void);
	unsigned short int GetMemory(void);
	float GetFrequency(void);
	float GetPriceTag(void);
	std::string GetName(void);
	std::string GetDate(void);
};