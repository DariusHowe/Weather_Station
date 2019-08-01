#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <sstream>
#include "Servers.h"
#include <map>

using namespace std;
//Object of Servers Class
Servers::Servers(){};
//Creating a get function for our Servers class that returns the string held withi a given key value
string Servers::get(string key)
{
if (var == NULL)
{var = new Servers();}
return language[key];
};
//Creating a load function for our Servers Class
void Servers::loadLang()
{
string name;
string key;
string val;
string line;
   //Create a reader for out knownLang.txt file
fstream * f1 = new fstream("knownLang.txt");
   //Creates a dynamic map named knownLanguages
map <string, string> knownLanguages;

while(!f1->eof())
{
    *f1 >> key;
    *f1 >> val;
    knownLanguages[key] = val;
}
cout <<"Which Language do you want to use?" <<endl;
   //Creating new iterator item named it
map<string, string>::iterator it;
   //For each line in knownLanguages document (start to finish), iterate
for (it = knownLanguages.begin(); it !=knownLanguages.end(); it++)
{
    std::cout << it->first
    <<std::endl;
}
cout<< "I am Choosing: " << endl;
getline(cin, name);
string myName = "lang." + knownLanguages[name];
   //Uses fstream to create new file reader
fstream * f = new fstream(myName);
   //Iterates through our lang. file selected, going from key to key and line to line displaying that text to the user
while (!f->eof())
{
   getline(*f, line);
   int pos = (int)line.find(" ");
   val = line.substr(pos +1);
   key = line.substr(0, pos);
    language[key]=val;
}
};
