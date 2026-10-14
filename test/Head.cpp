#include "Head.h"
Head::Head(std::vector<std::string>* vector, Reader* r) :array(vector), reader(r)
{
	result = "";
	argument = "";
	option = (*array)[1];
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
Head::Head(std::vector<std::string>* vector, Reader* r, string res) :array(vector), reader(r)
{
	argument = res;
	option = (*array)[1];
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
void Head::run()
{
	if ((option.size() > 7) || (option.size() < 3))
	{
		std::cout << "greska opcija nije lepo zadata" << std::endl;
	}
	else
	{
		int linije;
		try
		{
			linije = stoi(option.substr(2));
			int j = 0;
			std::string s = "";
			for (int i = 0;i < argument.size();i++)
			{
				if (argument[i] == '\n')
				{
					linije--;
				}
				if (linije == 0)
				{
					break;
				}
				s = s + argument[i];
			}
			result=s;
		}
		catch (...)
		{
			std::cout << "format opcije nije dobar" << std::endl;
		}

	}
}