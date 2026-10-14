#pragma once
#include"reader.h"
class Reader;
class Tr
{
public:
	void run();
	//Konstruktor kad je prva funkcija
	Tr(std::vector<std::string>* vector, Reader* r);
	//Konstruktor kada se funkcija nadje u pipu
	Tr(std::vector<std::string>* vector, Reader* r, string res);
private:
	string what;
	string with;
	std::vector<std::string>* array;
	Reader* reader;
	string result;
	string argument;
};

