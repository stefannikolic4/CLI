#include <iostream>
#include "reader.h"
int main()
{
    string znak = "$";
    string s = "";
    while (!cin.eof())
    {
        cout << znak;
        Reader* reader = new Reader();
        reader->readInstruction();
        if (reader->check())
            cout << "Greska previse ulaza i izlaza" << endl;
        s=reader->useInstruction();
        if (s != "")
            znak = s;
    }
}

