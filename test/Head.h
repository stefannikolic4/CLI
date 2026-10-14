#pragma once
#include"reader.h"
class Reader;
class Head
{
public:
	void run();
	Head(std::vector<std::string>* vector, Reader* r);
	//pipe
	Head(std::vector<std::string>* vector, Reader* r, string res);
private:
	string option;
	std::vector<std::string>* array;
	Reader* reader;
	string result;
	string argument;
};

