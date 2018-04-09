#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int a, b;

	cin >> a >> b;

	int sec = round((b-a)*1.0 / 100);

	// cout << sec << endl;
	// 
	

	int hour = sec / 3600;

	if (hour >= 0 && hour < 10) {
		cout << "0" << hour;
	} else {
		cout << hour;
	}

	cout << ":";

	int  minute = sec % 3600 / 60;

	if (minute >= 0 && minute < 10) {
		cout << "0" << minute;
	} else {
		cout << minute;
	}

	cout << ":";

	int second = sec % 3600 % 60;

	if(second >= 0 && second < 10) {
		cout << "0" << second;
	} else {
		cout << second;
	}

	return 0;
}