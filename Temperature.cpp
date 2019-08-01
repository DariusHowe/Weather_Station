#include "stdafx.h"
#include "Temperature.h"
#include <iostream>
#include <string>
#include <regex>
#include "CheckIt.h"
#include "Servers.h"


using namespace std;


string tempOutside()
{
	string temp = "";
	string endTemp;
	string validations = "[+-]?[0-9]{1,3}?";
	do
	{
		cout<< Servers::get("Tempy") << endl;
		//cout << "So whats the weather like outside in degrees?" << endl;
		getline(cin, temp);
	} while (!valid_input(temp, validations));
	//stringstream(temp) >> endTemp;
	return temp;

}

Temp Temp::setTempOutside()
{
	/*
	Temp result_t;
	*/
	
	temp = tempOutside();
	return *this;
}
