#pragma once
#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>
#include<string>
#include "Echo.h"
#include"Wc.h"
#include"Time.h"
#include"Date.h"
#include"Touch.h"
#include"Prompt.h"
#include"Truncate.h"
#include"Rm.h"
#include"Tr.h"
#include"Head.h"
#include"Batch.h"
#define MAX_INSTRUCTION_ARGUMENTS 5;



using namespace std;

class Reader
{
public:


	Reader() { error = false; }

	Reader(std::vector<std::string> vec) : array(vec) { error = false; }
	// Ucitava instrukciju sa ulaza u array
	void readInstruction();
	// Ucitava instukciju iz stringa u array(koristi se za batch)
	string readInstructionFromString(string s);
	// Zove komandu 
	string useInstruction();
	// Zove sledecu komandu u pipu
	void pipeInstruction(vector<string> *niz,string res);

	vector<string> getArray() { return array; }
	// Cita podatke iz fajla
	string input(string fileName);
	// Pise podatke u fajl
	void output(string filename, string str);

	bool check() { return error; }

	std::string getIn() { return in; }
	
	std::string getOut() { return out; }
private:

	std::vector<std::string> array;
	std::string in;
	std::string out;
	bool error;

};

