#pragma once

#include "stdafx.h"
#include <string>
#include "Wind.h"
#include "Temperature.h"

using namespace std;
/*struct wMeasure
{
	temperature myTemp;
	wind myWind;
};
*/

class wMeasurement
{
	Temp myTemp;
	Winds myWind;
	//wMeasure reading;
public:
	void printMeasurement(wMeasurement);
	wMeasurement setWeather();
};


