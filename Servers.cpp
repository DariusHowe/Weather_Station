#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <sstream>
#include "Servers.h"
#include <map>

using namespace std;
Servers::Servers(){};

string Servers::get(string key)
{
if (var == NULL)
{var = new Servers();}
return language[key];
};

void Servers::loadLang()
{
string name;
string key;
string val;
string line;
fstream * f1 = new fstream("knownLang.txt");
map <string, string> knownLanguages;

while(!f1->eof())
{
    *f1 >> key;
    *f1 >> val;
    knownLanguages[key] = val;
}
cout <<"Which Language do you want to use?" <<endl;
map<string, string>::iterator it;
for (it = knownLanguages.begin(); it !=knownLanguages.end(); it++)
{
    std::cout << it->first
    <<std::endl;
}
cout<< "I am Choosing: " << endl;
getline(cin, name);
string myName = "lang." + knownLanguages[name];
fstream * f = new fstream(myName);
while (!f->eof())
{
   getline(*f, line);
   int pos = (int)line.find(" ");
   val = line.substr(pos +1);
   key = line.substr(0, pos);
    language[key]=val;
}
};