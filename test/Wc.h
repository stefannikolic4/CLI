#pragma once
#include"Echo.h"
class Reader;
class Wc
{
public:

	void run();

	Wc(std::vector<std::string>* vector, Reader* r);
	//pipe
	Wc(std::vector<std::string>* vector, Reader* r,string res);
private:
	char option;
	std::vector<std::string>* array;
	Reader* reader;
	string result;
	string argument;
};

