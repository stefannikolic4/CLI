#pragma once
#include "Time.h"
class Reader;
class Date 
{
public:

	void run();

	Date(std::vector<std::string>* vector, Reader* r);

private:
	std::vector<std::string>* array;
	Reader* reader;
	string result;
};

