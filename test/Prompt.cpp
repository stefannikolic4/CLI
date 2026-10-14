#include "Prompt.h"
Prompt::Prompt(std::vector<std::string>* vector, Reader* r) :array(vector), reader(r)
{
	argument = "";
	bool pipe = false;
	if ((*array).size() > 2)
	{
		cout << "Greska previse argumenata" << endl;
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
			argument = reader->input(reader->getIn());
		}
	}
	if (argument == "") return;
	
}