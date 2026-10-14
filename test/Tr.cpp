#include "Tr.h"
Tr::Tr(std::vector<std::string>* vector, Reader* r):array(vector),reader(r)
{
	result = "";
	argument = "";
	bool pipe = false;
	if ((*array).size() > 4)
	{
		if ((*array)[2] == "|")
		{
			if (((*array)[1][0] == '"') && ((*array)[1].back())=='"')
			{

				what = (*array)[1].substr(1, (*array)[1].size() - 2);
			}
			else
			{
				cout << "what nije lepo definisan\n";
				return;
			}
			with = "";
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

			if (((*array)[2][0] == '"') && ((*array)[2].back()) == '"')
			{

				what = (*array)[2].substr(1, (*array)[2].size() - 2);
			}
			else
			{
				cout << "what nije lepo definisan\n";
				return;
			}
			with = "";
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
			//subvector 3-n
			run();
			std::vector<std::string> v2((*array).begin() + 4, (*array).end());
			reader->pipeInstruction(&v2, result);
		}
		else  if ((*array)[4] == "|")
		{
			if (((*array)[2][0] == '"') && ((*array)[2].back()) == '"')
			{

				what = (*array)[2].substr(1, (*array)[2].size() - 2);
			}
			else
			{
				cout << "what nije lepo definisan\n";
				return;
			}
			if (((*array)[3][0] == '"') && ((*array)[3].back()) == '"')
			{

				with = (*array)[3].substr(1, (*array)[3].size() - 2);
			}
			else
			{
				cout << "with nije lepo definisan\n";
				return;
			}
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
			//subvector 4-n
			run();
			std::vector<std::string> v2((*array).begin() + 5, (*array).end());
			reader->pipeInstruction(&v2, result);
		}
		else
		{
			cout << "Greska u broju argumenata" << endl;
		}
	}
	else if ((*array).size() == 4)
	{
		if ((*array)[2] == "|")
		{
			if (((*array)[1][0] == '"') && ((*array)[1].back()) == '"')
			{

				what = (*array)[1].substr(1, (*array)[1].size() - 2);
			}
			else
			{
				cout << "what nije lepo definisan\n";
				return;
			}
			with = "";
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
		else
		{
			if (((*array)[2][0] == '"') && ((*array)[2].back()) == '"')
			{

				what = (*array)[2].substr(1, (*array)[2].size() - 2);
			}
			else
			{
				cout << "what nije lepo definisan\n";
				return;
			}
			if (((*array)[3][0] == '"') && ((*array)[3].back()) == '"')
			{

				with = (*array)[3].substr(1, (*array)[3].size() - 2);
			}
			else
			{
				cout << "with nije lepo definisan\n";
				return;
			}
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
	}
	else if ((*array).size() == 3) 
	{
		if (((*array)[2][0] == '"') && ((*array)[2].back()) == '"')
		{

			what = (*array)[2].substr(1, (*array)[2].size() - 2);
		}
		else
		{
			cout << "what nije lepo definisan\n";
			return;
		}
		with = "";
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
	else  if ((*array).size() == 2)
	{
		if (((*array)[1][0] == '"') && ((*array)[1].back()) == '"')
		{

			what = (*array)[1].substr(1, (*array)[1].size() - 2);
		}
		else
		{
			cout << "what nije lepo definisan\n";
			return;
		}
		with = "";
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
Tr::Tr(std::vector<std::string>* vector, Reader* r, string res):array(vector),reader(r)
{
	argument = res;

	if ((*array).size() == 1)
	{
		cout << "greska premalo argumenata" << endl;
	}
	else if ((*array).size() == 2)
	{
		if (((*array)[1][0] == '"') && ((*array)[1].back()) == '"')
		{

			what = (*array)[1].substr(1, (*array)[1].size() - 2);
		}
		else
		{
			cout << "what nije lepo definisan\n";
			return;
		}
		with = "";
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
	else if ((*array).size() == 3)
	{
		if (((*array)[1][0] == '"') && ((*array)[1].back()) == '"')
		{

			what = (*array)[1].substr(1, (*array)[1].size() - 2);
		}
		else
		{
			cout << "what nije lepo definisan\n";
			return;
		}
		if (((*array)[2][0] == '"') && ((*array)[2].back()) == '"')
		{

			with = (*array)[2].substr(1, (*array)[2].size() - 2);
		}
		else
		{
			cout << "with nije lepo definisan\n";
			return;
		}
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
	else
	{
		if ((*array)[2] == "|")
		{
			if (((*array)[1][0] == '"') && ((*array)[1].back()) == '"')
			{

				what = (*array)[1].substr(1, (*array)[1].size() - 2);
			}
			else
			{
				cout << "what nije lepo definisan\n";
				return;
			}
			with = "";
			run();
			std::vector<std::string> v2(array->begin() + 3, array->end());
			reader->pipeInstruction(&v2, result);
		}
		else if ((*array)[3] == "|")
		{
			if (((*array)[1][0] == '"') && ((*array)[1].back()) == '"')
			{

				what = (*array)[1].substr(1, (*array)[1].size() - 2);
			}
			else
			{
				cout << "what nije lepo definisan\n";
				return;
			}
			if (((*array)[2][0] == '"') && ((*array)[2].back()) == '"')
			{

				with = (*array)[2].substr(1, (*array)[2].size() - 2);
			}
			else
			{
				cout << "with nije lepo definisan\n";
				return;
			}
			run();
			std::vector<std::string> v2(array->begin() + 4, array->end());
			reader->pipeInstruction(&v2, result);
		}
		else
		{
			cout << "Greska pri pipu previse argumenata" << endl;
		}
	}
}
void Tr::run()
{
	int tren = 0;
	while (tren < argument.size())
	{
		tren = argument.find(what, tren);
		if (tren == -1) break;
		argument.replace(tren, what.size(), with);
		tren += with.size();
	}
	result=argument;
}