#include "Touch.h"
Touch::Touch(std::vector<std::string>* vector, Reader* r) : array(vector), reader(r)
{
	filename = "";
	bool pipe = false;
	if ((*array).size() > 2)
	{
			cout << "Greska previse argumenata" << endl;
	}
	else if ((*array).size() == 2) {
		if (reader->getIn() == "")
		{
			string s = (*array)[1];
			filename = s;
		}
		else
		{
			cout << "Greska uneli ste 2 argumenta" << endl;
		}
	}
	else  if ((*array).size() == 1)
	{
		cout << "Greska fali argumenat" << endl;
	}
	if (filename == "") return;
	if (!pipe)
	{
		run();
	}
}
void Touch::run() 
{
	try {
		std::ifstream test(this->filename);
		test.close();
		if (test.good())
		{
			throw 1;
		}
		std::ofstream f(this->filename);
		f.close();
	}
	catch (...)
	{
		cout <<"Greska!Fajl vec postoji!\n";

	}
	
}

