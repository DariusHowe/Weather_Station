#include "stdafx.h"
#include "WeatherMeasurement.h"
#include "Wind.h"
#include "Temperature.h"
#include <iostream>
#include <string>
#include <regex>
#include "Servers.h"

using namespace std;
/*class wMeas
{
wMeasure reading;
public:
void printMeasurement(wMeasure);
};
*/


/*
int myStation()
{
string station;
cout << "What do you want to Name your brand new Weather Station?" << endl;
getline(cin, station);
cout << "Welcome to the " << station << " Weather Station on BlackBoi News!" << endl;
return  -1;
}
*/


wMeasurement wMeasurement::setWeather()
{
	wMeasurement reading;
	myTemp.setTempOutside();
	myWind.setWindInstructs();
	return *this;
}

void wMeasurement::printMeasurement(wMeasurement reading)
{
	cout << Servers::get("WR1") << reading.myTemp.temp << Servers::get("WR2") << endl;
	//cout << "Current Temperature is: " << reading.myTemp.temp << " degrees Fahrenheit" << endl;

	cout << Servers::get("WS1") << reading.myWind.wspeed << Servers::get("WD1") << reading.myWind.wDirect << endl;
	//cout << "The wind speed is currently: " << reading.myWind.wspeed << "mph at a direction " << reading.myWind.wDirect << endl;
}
