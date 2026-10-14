#include "reader.h"
#include <fstream>

void Reader::readInstruction() {



	in = "";
	out = "";
	error = false;
	string line;
	getline(cin, line);
	bool poc = false;
	int start = 0;
	int end = 0;
	std::string name;
	std::vector<std::string> v;
	bool navodnici = false;
	for (int i = 0;(i < line.size()) && (i < 512);i++)
	{
		if (line[i] == '|')
		{
			if (navodnici)
			{
				end = i - 1;
				name = line.substr(start, end - start + 1);
				v.push_back(name);
				navodnici = false;
			}
			else
			{
				if (poc)
				{
					end = i;
					name = line.substr(start, end - start);
					v.push_back(name);
				}
				poc = false;
			}
			v.push_back("|");
			continue;
		}
		if (line[i] == '"')
		{
			if (navodnici)
			{	
				end = i;
				name = line.substr(start, end - start + 1);
				v.push_back(name);
				navodnici = false;
				continue;
			}
			else
			{
				start = i;
				navodnici = true;
			}
		}
		if (navodnici) continue;
		if (std::isspace(line[i]))
		{
			if (poc)
			{
				end = i;
				name = line.substr(start, end - start);
				v.push_back(name);
			}
			poc = false;
		}
		else
		{
			if (!poc) start = i;
			poc = true;
		}
	}
		if ((poc) && (line.size() > 512))
		{
			name = line.substr(start, 512 - start);
			v.push_back(name);
		}
		else if (poc)
		{
			name = line.substr(start);
			v.push_back(name);
		}
		if (navodnici)
		{
			name = line.substr(start);
			v.push_back(name);
		}
		
		for (int i = 0;i < v.size();i++)
		{
			if ((v[i][0] == '<') && (v[i].size() == 1) && (i != v.size() - 1))
			{
				v[i] = v[i] + v[i + 1];
				v.erase(v.begin() + i + 1);
				if (in != "")
				{
					error = true;
					break;
				}
				in = v[i];
				v.erase(v.begin() + i);
				i--;
			}
			else if ((v[i][0] == '>') && (v[i].size() == 1) && (i != v.size() - 1))
			{
				v[i] = v[i] + v[i + 1];
				v.erase(v.begin() + i + 1);
				if (out != "")
				{
					error = true;
					break;
				}
				out = v[i];
				v.erase(v.begin() + i);
				i--;
			}
			else if ((v[i][0] == '>') && (v[i].size() == 2) && (i != v.size() - 1) && (v[i][1] == '>'))
			{
				v[i] = v[i] + v[i + 1];
				v.erase(v.begin() + i + 1);
				if (out != "")
				{
					error = true;
					break;
				}
				out = v[i];
				v.erase(v.begin() + i);
				i--;
			}
			else if (v[i][0] == '<')
			{
				if (in != "")
				{
					error = true;
					break;
				}
				in = v[i];
				v.erase(v.begin() + i);
				i--;
			}
			else if (v[i][0] == '>')
			{
				if (out != "")
				{
					error = true;
					break;
				}
				out = v[i];
				v.erase(v.begin() + i);
				i--;
			}
		}

		array = v;
	

}
string Reader::readInstructionFromString(string s)
{
	in = "";
	out = "";
	error = false;
	string line;
	
	int kraj2 = 0;
	kraj2 = s.find('\n', 0);

	if (kraj2 == -1)
	{
		line = s.substr(0);
	}
	line = s.substr(0, kraj2 - 0);
	//
	bool poc = false;
	int start = 0;
	int end = 0;
	std::string name;
	std::vector<std::string> v;
	bool navodnici = false;
	for (int i = 0;(i < line.size()) && (i < 512);i++)
	{
		if (line[i] == '|')
		{
			if (navodnici)
			{
				end = i - 1;
				name = line.substr(start, end - start + 1);
				v.push_back(name);
				navodnici = false;
			}
			else
			{
				if (poc)
				{
					end = i;
					name = line.substr(start, end - start);
					v.push_back(name);
				}
				poc = false;
			}
			v.push_back("|");
			continue;
		}
		if (line[i] == '"')
		{
			if (navodnici)
			{
				end = i;
				name = line.substr(start, end - start + 1);
				v.push_back(name);
				navodnici = false;
				continue;
			}
			else
			{
				start = i;
				navodnici = true;
			}
		}
		if (navodnici) continue;
		if (std::isspace(line[i]))
		{
			if (poc)
			{
				end = i;
				name = line.substr(start, end - start);
				v.push_back(name);
			}
			poc = false;
		}
		else
		{
			if (!poc) start = i;
			poc = true;
		}
	}
	if ((poc) && (line.size() > 512))
	{
		name = line.substr(start, 512 - start);
		v.push_back(name);
	}
	else if (poc)
	{
		name = line.substr(start);
		v.push_back(name);
	}
	if (navodnici)
	{
		name = line.substr(start);
		v.push_back(name);
	}
	for (int i = 0;i < v.size();i++)
	{
		if ((v[i][0] == '<') && (v[i].size() == 1) && (i != v.size() - 1))
		{
			v[i] = v[i] + v[i + 1];
			v.erase(v.begin() + i + 1);
			if (in != "")
			{
				error = true;
				break;
			}
			in = v[i];
			v.erase(v.begin() + i);
			i--;
		}
		else if ((v[i][0] == '>') && (v[i].size() == 1) && (i != v.size() - 1))
		{
			v[i] = v[i] + v[i + 1];
			v.erase(v.begin() + i + 1);
			if (out != "")
			{
				error = true;
				break;
			}
			out = v[i];
			v.erase(v.begin() + i);
			i--;
		}
		else if ((v[i][0] == '>') && (v[i].size() == 2) && (i != v.size() - 1) && (v[i][1] == '>'))
		{
			v[i] = v[i] + v[i + 1];
			v.erase(v.begin() + i + 1);
			if (out != "")
			{
				error = true;
				break;
			}
			out = v[i];
			v.erase(v.begin() + i);
			i--;
		}
		else if (v[i][0] == '<')
		{
			if (in != "")
			{
				error = true;
				break;
			}
			in = v[i];
			v.erase(v.begin() + i);
			i--;
		}
		else if (v[i][0] == '>')
		{
			if (out != "")
			{
				error = true;
				break;
			}
			out = v[i];
			v.erase(v.begin() + i);
			i--;
		}
	}
	array = v;
	if (kraj2 == -1) return "";
	return s.substr(kraj2+1);
}


string Reader::useInstruction()
{
	if (array.size() == 0) return "";
	if ((array)[0] == "echo") {
		Echo* e = new Echo(&array, this);
		delete e;
	}
	else if ((array)[0] == "wc")
	{
		Wc* w = new Wc(&array, this);
		delete w;
	}
	else if ((array)[0] == "time")
	{
		Time* w = new Time(&array, this);
		delete w;
	}
	else if ((array)[0] == "date")
	{
		Date* w = new Date(&array, this);
		delete w;
	}
	else if ((array)[0] == "touch")
	{
		Touch* w = new Touch(&array, this);
		delete w;
	}
	else if ((array)[0] == "prompt")
	{
		Prompt* w = new Prompt(&array, this);
		string s = w->GetResult();
		delete w;
		return s;
	}
	else if ((array)[0] == "truncate")
	{
		Truncate* w = new Truncate(&array, this);
		delete w;
	}
	else if ((array)[0] == "rm")
	{
		Rm* w = new Rm(&array, this);
		delete w;
	}
	else if ((array)[0] == "tr")
	{
		Tr* w = new Tr(&array, this);
		delete w;
	}
	else if ((array)[0] == "head")
	{
		Head* w = new Head(&array, this);
		delete w;
	}
	else if ((array)[0] == "batch")
	{
		Batch* w = new Batch(&array, this);
		delete w;
	}
	else
	{
		cout << "Greska komanda "+(array)[0]+" ne postoji\n";
	}
	return "";
}

void Reader::pipeInstruction(vector<string> *niz,string res)
{
	if ((*niz)[0] == "echo")
	{
		Echo* e = new Echo(niz, this, res);
		delete e;
	}
	else if ((*niz)[0] == "wc")
	{
		Wc* w = new Wc(niz, this, res);
		delete w;
	}
	else if ((*niz)[0] == "tr")
	{
		Tr* w = new Tr(niz, this, res);
		delete w;
	}
	else if ((*niz)[0] == "head")
	{
		Head* w = new Head(niz, this, res);
		delete w;
	}
	else if ((*niz)[0] == "batch")
	{
		Batch* w = new Batch(niz, this, res);
		delete w;
	}
	else
	{
		cout << "komanda nije podrzana za pipe\n";
	}
}
string Reader::input(string fileName) {
	string argument1 = "";
	if (fileName[0] == '<')
	{
		try {
			std::string s2 = fileName.substr(1);
			std::ifstream file(s2);
			if (!file.good()) throw 1;
			std::string line;
			argument1 = "";
			while (std::getline(file, line))
			{
				argument1 += line + "\n";
			}
			file.close();
		
		}
		catch (...)
		{
			cout <<"Greska fajl nije pronadjen\n";
		}
	}
	else
	{
		try {

			std::ifstream file(fileName);
			if (!file.good()) throw 1;
			std::string line;
			argument1 = "";
			while (std::getline(file, line))
			{
				argument1 += line + "\n";
			}
			file.close();

		}
		catch (...)
		{
			cout << "Greska fajl nije pronadjen\n";
		}
	}
	return argument1;
}
void Reader::output(string filename, string str)
{
	if ((filename[0] == '>') && (filename[1] == '>'))
	{
		std::string s2 = filename.substr(2);
		std::ofstream f(s2, std::ios_base::app);
		f << str;
		f.close();
	}
	else
	{
		if (filename[0] == '>')
		{
			std::string s2 = filename.substr(1);
			std::ofstream f(s2);
			f << str;
			f.close();
		}
		else
		{
			std::ofstream f(filename);
			f << str;
			f.close();
		}
	}
}