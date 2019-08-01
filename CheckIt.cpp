
#include "stdafx.h"
#include <string>
#include "CheckIt.h"
#include <regex>

using namespace std;

bool valid_input(string input, string validation)

{
	const char* test = input.c_str();
	regex word(validation);
	cmatch match;
	if (regex_match(test, match, word))
	{
		return true;
	}
	else
	{
		return false;
	}
}
