#include "stdafx.h"
#include "Wind.h"
#include <iostream>
#include <string>
#include <regex>
#include "CheckIt.h"
#include "Servers.h"


using namespace std;
string windSpeed()
{
	string wspeed;
	//string endSpeed;
	string validation = "[0-9]{1,3}";
	do
	{
		cout << Servers::get("Speed") << endl;
		//cout << "How strong are the winds (Enter a number please)?" << endl;

		getline(cin, wspeed);
	} while (!valid_input(wspeed, validation));
	//stringstream(wspeed) >> endSpeed;
	return wspeed;
}

string windDirect()
{
	string wDirect;
	//string endDirect;
	string validation1 = "North|South|East|West|north|south|east|west";
	do
	{
		cout << Servers::get("Direct") << endl;
		//cout << "What direction is the wind Blowing?" << endl;;
		
		cout << Servers::get("Explain") << endl;
		//cout << "Example: North or north" << endl;
		getline(cin, wDirect);
	} while (!valid_input(wDirect, validation1));
	//stringstream(wDirect) >> endDirect;
	return wDirect;
}

Winds Winds::setWindInstructs()
{
	wspeed = windSpeed();
	wDirect = windDirect();
	return *this;
};
