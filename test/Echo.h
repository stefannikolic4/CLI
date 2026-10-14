#pragma once
#include <vector>
#include <iostream>
#include<string>
using namespace std;
#include "reader.h"
class Reader;

class Echo
{


public:
	//Konstruktor za funkciju
	Echo(std::vector<std::string>* vector, Reader* r);
	//Konstruktor za pipe
	Echo(std::vector<std::string>* vector, Reader* r, std::string result);

	//Racuna funkciju i vraca result
	virtual void run();

protected:

	std::vector<std::string>* array;
	Reader* reader;
	string result;
	string argument;


};

