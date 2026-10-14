#pragma once
#include"reader.h"
class Reader;
class Rm
{
public:
	//Konstruktor
	Rm(std::vector<std::string>* vector, Reader* r);
	//Pokrece funkciju
	virtual void run();

protected:

	std::vector<std::string>* array;
	Reader* reader;
	std::string filename;
};

