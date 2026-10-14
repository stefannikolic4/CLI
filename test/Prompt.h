#pragma once
#include"reader.h"
class Reader;
class Prompt
{
public:

	Prompt(std::vector<std::string>* vector, Reader* r);

	string GetResult()
	{
		return argument;
	}

protected:

	std::vector<std::string>* array;
	Reader* reader;
	std::string argument;
};

