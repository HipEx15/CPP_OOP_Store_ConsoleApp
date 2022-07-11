#include "Products.h"

Products::Products(void)
{
	this->weight = 0;
	this->height = 0;
	this->tdp = 0;
	this->nms = 0;
	this->memory = 0;
	this->frequency = 0;
	this->priceTag = 0;
	this->name = "?";
	this->date = "?";
}

Products::Products(float weight, float height, unsigned short int tdp, unsigned short int nms, unsigned short int memory, float frequency, float priceTag, std::string Name, std::string Date)
{
	this->weight = weight;
	this->height = height;
	this->tdp = tdp;
	this->nms = nms;
	this->memory = memory;
	this->frequency = frequency;
	this->priceTag = priceTag;
	this->name = Name;
	this->date = Date;
}

void Products::PrintP(void)
{
	std::cout << "\n\tName: " << this->GetName() << "\n\tDate: " << this->GetDate() << "\n\tPrice Tag: " << this->GetPriceTag() << " lei\n\tWeight: " << this->GetWeight() << " grams\n\tHeight: " << this->GetHeight() << " cms\n\tTDP: " << this->GetTDP() << " watts\n\tNMS: " << this->GetNMS() << " n\n\tMemory:" << this->GetMemory() << " MB\n\tFrequency: " << this->GetFrequency() << " MHz";
}

float Products::GetWeight(void)
{
	return this->height;
}

float Products::GetHeight(void)
{
	return this->height;
}

unsigned short int Products::GetTDP(void)
{
	return this->tdp;
}

unsigned short int Products::GetNMS(void)
{
	return this->nms;
}

unsigned short int Products::GetMemory(void)
{
	return this->memory;
}

float Products::GetFrequency(void)
{
	return this->frequency;
}

float Products::GetPriceTag(void)
{
	return this->priceTag;
}

std::string Products::GetName(void)
{
	return this->name;
}

std::string Products::GetDate(void)
{
	return this->date;
}
