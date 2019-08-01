#pragma once

#include <fstream>
#include <regex>
#include <string>
#include <sstream>
#include <map>

using namespace std;

class Servers
{
static map <string, string > language;
Servers();
static Servers * var;
public:
static string get(string key);
static void loadLang();
};