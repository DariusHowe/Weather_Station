// Classes Project 8.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <string>
#include <regex>
#include "WeatherMeasurement.h"
#include <sstream>
#include "Servers.h"


using namespace std;

Servers *Servers::var=0;
map<string, string> Servers::language;

int main()
{
	wMeasurement meep;

	string station;

	Servers::loadLang();

	cout << Servers::get("Name")<<endl;
	
	getline(cin, station);

	char pickMe;
	int fullHouse = 0;
	int weatherIndex = 0;
	int weatherCount = 0;

	//Used for Dyn. Mem Allocation

	int weatherSize = 0;
	int MemPointer = weatherSize;

	
	cout << Servers::get("Size") << endl;
	
	cin >> MemPointer;
	weatherSize = MemPointer;
	if (MemPointer == 0)
		do
		{

			cout << Servers::get("SizeTwice") << endl;
			
			cin >> MemPointer;
			weatherSize = MemPointer;
		} while (MemPointer == 0);

		

		wMeasurement * history;
		history = new (nothrow) wMeasurement[MemPointer];
	



		do
		{
			cout << Servers::get("Pane") << endl;
		
			
			cout << Servers::get("Reading") << endl;

			cout << Servers::get("Recent") <<endl;

			cout << Servers::get("Total") << endl;

			cout << Servers::get("Bye") << endl;

			cin >> pickMe;
			switch (pickMe)

			{
			case '1': //Input of Weather functions from comments here
				if (weatherCount >= MemPointer)
				{
					cout << Servers::get("Filled") << endl;
					break;
				}
				else
				{
				history[weatherIndex] = meep.setWeather();
				weatherIndex++;


				weatherCount++;
				fullHouse = 1;
				}
					
				break;


			case '2': //Printing of the Weather Data
				if (pickMe == '2')
				{
				if (fullHouse == 0)
				{
					cout << Servers::get(" Error") << endl;

					cout << Servers::get("Error2") << endl;
				}

				else
				{
					cout << Servers::get("Welcome1") << station << Servers::get("Welcome2") << endl;
					meep.printMeasurement(history[weatherIndex - 1]);
					cout << Servers::get("Werido") << endl;
				}
				}
				

				break;
			case '3': //Print Weather History
				if (pickMe == '3')
					for (int i = 0; i<(weatherCount <= MemPointer ? weatherCount : MemPointer); i++)
					{
						meep.printMeasurement(history[i]);
						cout << Servers::get("Werido") << endl;
					}



				break;


			case '4': //Exit
				if (pickMe == '4')
					cout << Servers::get("Farewell") << endl;

				cout << Servers::get("Werido") << endl;
				break;


			default: //Wrong answer
				cout << Servers::get("Bad") << endl;

				cout << Servers::get("Werido") << endl;
			}

		} while (pickMe != '4');
		return 0;
}



