#include "Time.h"
Time::Time(std::vector<std::string>* vector, Reader* r):array(vector),reader(r)
{
	result = "";
	bool pipe = false;
	if ((*array).size() > 1)
	{
		if ((*array)[1] == "|")
		{
			pipe = true;
			//sub vector 1-n
			run();
			std::vector<std::string> v2((*array).begin() + 2, (*array).end());
			reader->pipeInstruction(&v2, result);
		}
		else
		{
			cout << "Greska previse argumenata" << endl;
		}
	}
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
void Time::run()
{
	time_t t;
	struct tm vreme;
	t = std::time(NULL);
	localtime_s(&vreme, &t);
	result=std::to_string(vreme.tm_hour) + ":" + std::to_string(vreme.tm_min) + ":" + std::to_string(vreme.tm_sec);
}