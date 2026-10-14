#pragma once
#include"reader.h"
class Reader;
class Truncate
{
public:

	Truncate(std::vector<std::string>* vector, Reader* r);

	virtual void run();

protected:

	std::vector<std::string>* array;
	Reader* reader;
	std::string filename;
};

