#pragma once
#include<vector>
#include<string>
#include<fstream>
#include"reader.h"
class Reader;
class Touch
{
public:

	Touch(std::vector<std::string>* vector, Reader* r);

	virtual void run();

protected:

	std::vector<std::string>* array;
	Reader* reader;
	std::string filename;
};

