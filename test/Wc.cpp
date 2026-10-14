#include "Wc.h"
Wc::Wc(std::vector<std::string>* vector, Reader* r):array(vector),reader(r)
{
	result = "";
	argument = "";
	option = (*array)[1][1];
	bool pipe = false;
	if ((*array).size() > 3)
	{
		if ((*array)[2] == "|")
		{
			if (reader->getIn() == "")
			{
				std::string line;
				argument = "";
				while (std::getline(std::cin, line))
				{
					argument += line + "\n";
				}
				clearerr(stdin);
				std::cin.clear();
			}
			else
			{
				//argument iz fajla
				argument = reader->input(reader->getIn());
			}
			pipe = true;
			//sub vector 2-n
			run();
			std::vector<std::string> v2((*array).begin() + 3, (*array).end());
			reader->pipeInstruction(&v2, result);
		}
		else if ((*array)[3] == "|")
		{
			if (reader->getIn() == "")
			{
				string s = (*array)[2];
				if ((s[0] == '"') && (s.back() == '"'))
				{
					argument = s.substr(1, s.size() - 2);
				}
				else
				{
					//iz fajla
					argument = reader->input(s);
				}
			}
			else
			{
				cout << "Greska uneli ste 2 argumenta" << endl;
			}
			pipe = true;
			//subvector 3-n
			run();
			std::vector<std::string> v2((*array).begin() + 4, (*array).end());
			reader->pipeInstruction(&v2, result);
		}
		else
		{
			cout << "Greska u broju argumenata" << endl;
		}
	}
	else if ((*array).size() == 3) {
		if (reader->getIn() == "")
		{
			string s = (*array)[2];
			if ((s[0] == '"') && (s.back() == '"'))
			{
				argument = s.substr(1, s.size() - 2);
			}
			else
			{
				//iz fajla
				argument = reader->input(s);
			}
		}
		else
		{
			cout << "Greska uneli ste 2 argumenta" << endl;
		}
	}
	else  if ((*array).size() == 2)
	{
		if (reader->getIn() == "")
		{
			std::string line;
			argument = "";
			while (std::getline(std::cin, line))
			{
				argument += line + "\n";
			}
			clearerr(stdin);
			std::cin.clear();
		}
		else
		{
			//argument iz fajla
			argument = reader->input(reader->getIn());
		}
	}
	else
	{
		cout << "greska previse malo argumenata" << endl;
	}
	if (argument == "") return;
	if (!pipe)
	{
		run();
		if (reader->getOut() == "")
		{
			cout << result << endl;
		}
		else
		{
			reader->output(reader->getOut(), result);
		}
	}
}
Wc::Wc(std::vector<std::string>* vector, Reader* r, string res) :array(vector), reader(r)
{
	argument = res;
	option = (*array)[1][1];
	run();
	if ((*array).size() == 1)
	{
		cout << "greska premalo argumenata" << endl;
	}
	else if ((*array).size() == 2)
	{
		if (reader->getOut() == "")
		{
			cout << result << endl;
		}
		else
		{
			reader->output(reader->getOut(), result);
		}
	}
	else
	{
		if ((*array)[2] == "|")
		{
			std::vector<std::string> v2(array->begin() + 3, array->end());
			reader->pipeInstruction(&v2, result);
		}
		else
		{
			cout << "Greska pri pipu previse argumenata" << endl;
		}
	}
}
void Wc::run()
{
	if (argument == "") return;
	bool rec = false;
	int i = 0;
	int CountWords = 0;
	int CountCharacters = 0;
	while (argument[i] != '\0')
	{
		if (std::isspace(argument[i]))
		{
			rec = false;
			CountCharacters++;
		}
		else
		{
			if (rec == false) CountWords++;
			rec = true;
			CountCharacters++;
		}
		i++;
	}
	if (option == 'w')
	{
		result = to_string(CountWords);
	}
	else
	{
		if (option == 'c')
		{
			result=to_string(CountCharacters);
		}
		else
		{
			cout<<"Greska,ne postoji ta opcija\n";
			result = "";
		}
	}
}