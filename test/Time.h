#pragma once
#include"reader.h"
class Reader;
class Time
{
public:
	//Pokrece funkciju
	virtual void run();
	//Konstruktor za time
	Time(std::vector<std::string>* vector, Reader* r);
private:
	std::vector<std::string>* array;
	Reader* reader;
	string result;
};

