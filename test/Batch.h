#pragma once
#include "reader.h"
class Reader;
class Batch
{
public:

	Batch(std::vector<std::string>* vector, Reader* r);
	//pipe
	Batch(std::vector<std::string>* vector, Reader* r, std::string result);


	 void run();

protected:

	std::vector<std::string>* array;
	Reader* reader;
	string result;
	string argument;


};

