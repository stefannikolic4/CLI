#include "Echo.h"

Echo::Echo(std::vector<std::string>* vector, Reader* r): array(vector), reader(r) 
{
	result = "";
	argument = "";
	bool pipe = false;
	if ((*array).size() > 2)
	{
		if ((*array)[1] == "|")
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

			//sub vector 1-n
			run();
			std::vector<std::string> v2((*array).begin() + 2, (*array).end());
			reader->pipeInstruction(&v2, result);
		}
		else if ((*array)[2] == "|")
		{
			if (reader->getIn() == "")
			{
				string s = (*array)[1];
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
			//subvector 2-n
			run();
			std::vector<std::string> v2((*array).begin() + 3, (*array).end());
			reader->pipeInstruction(&v2, result);
		}
		else
		{
			cout << "Greska previse argumenata" << endl;
		}
	}
	else if ((*array).size() == 2) {
		if (reader->getIn() == "")
		{
			string s = (*array)[1];
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
	else  if ((*array).size() == 1)
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
			argument=reader->input(reader->getIn());
		}
	}
	if (argument == "") return;
	if (!pipe)
	{
		run();
		if (reader->getOut() == "")
		{
			cout << result<<endl;
		}
		else
		{
			reader->output(reader->getOut(), result);
		}
	}
}
Echo::Echo(std::vector<std::string>* vector, Reader* r, string res) :array(vector), reader(r)
{
	argument = res;
	run();
	if ((*array).size()==1)
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
		if ((*array)[1] == "|")
		{
			std::vector<std::string> v2(array->begin() + 2, array->end());
			reader->pipeInstruction(&v2, result);
		}
		else
		{
			cout << "Greska pri pipu previse argumenata" << endl;
		}
	}
}
void Echo::run() {

	result = argument;

}

