#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
//getting filename until there is a file
void database(string &routeFileName, string &timeFileName, ifstream &routeData, ifstream &timeData) {
	while (true) {
		cout << "Please enter a filename for route database: ";
		cin >> routeFileName;
		routeData.open(routeFileName.c_str());
		if (routeData.fail()) {
			cout << "cannot open routes database file" << endl;
			routeData.clear();
		}
		else {
			break;
		}
	}
	while (true) {
		cout << "Please enter a filename for time database: ";
		cin >> timeFileName;
		timeData.open(timeFileName.c_str());
		if (timeData.fail()) {
			cout << "cannot open times database file" << endl;
			timeData.clear();
		}
		else {
			break;
		}
	}
}
//checking hour:minute input whether is in correct format or not
bool validInput(string &inputTime) {
	if (inputTime.length() != 5 || inputTime[2] != ":"[0]) {
		cout << "Time is not in correct format ";
		return false;
	}
	for (int i = 0; i < 5; i++) {
		if (i == 2)
			continue;  // Skip the ':' separator
		if (inputTime[i]<48 || inputTime[i]>57) {
			cout << "Time is not in correct format ";
			return false;
		}
	}
	string hourStr = inputTime.substr(0, 2);
	string minuteStr = inputTime.substr(3, 2);
	int hour = stoi(hourStr);
	int minute = stoi(minuteStr);
	bool last = (hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59);
	if (last == false) {
		cout << "Time is not in correct format ";
		return false;
	} 
	else {
		return true;
	}
}
//finding appropriate routes if exist
void find(ifstream &routeData, ifstream &timeData, string &inputLocation, string &inputTime, string &timeFileName, string &routeFileName) {
	string a, b;
	string routeID, routeStart, routeEnd;
	string timeID, departureTime;
	cout << "The search results are: " << endl;
	while (getline(routeData, a)) {
		stringstream lineStream(a);
		lineStream >> routeID >> routeStart >> routeEnd;
		if (routeStart == inputLocation) {
			while (getline(timeData, b)) {
				stringstream lineStream(b);
				lineStream >> timeID >> departureTime;
				if (routeID == timeID) {
					if (departureTime.substr(0, 2) > inputTime) {
						cout << routeStart << " " << routeEnd << " " << departureTime << endl;
					}
					else if (departureTime.substr(0, 2) == inputTime.substr(0,2)) {
						if (departureTime.substr(3, 2) >= inputTime.substr(3, 2)) {
							cout << routeStart << " " << routeEnd << " " << departureTime << endl;
						}
					}
				}
			}
			timeData.close();
			timeData.open(timeFileName.c_str());
		}
	}
	routeData.close();
	routeData.open(routeFileName.c_str());
}
int main() {
	ifstream routeData, timeData;
	string routeFileName, timeFileName, inputLocation, inputTime;
	database(routeFileName, timeFileName, routeData, timeData);
	while (true) {
		cout << "Please enter departure location: ";
		cin >> inputLocation;
		if (inputLocation == "EXIT") {
			break;
		}
		while (true) {
			cout << "Please enter start time of travel: ";
			cin >> inputTime;
			if (validInput(inputTime)) {
				break;
			}
			cout << endl;
		}
		find(routeData, timeData, inputLocation, inputTime, timeFileName, routeFileName);
	}
	return 0;
}
