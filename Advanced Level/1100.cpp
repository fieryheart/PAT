#include <bits/stdc++.h>
//#include <iostream>
//#include <map>
//#include <string>
//#include <algorithm>
using namespace std;
string Mars1[] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string Mars2[] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
map<string, int> MarsToEarth;
map<int, string> EarthToMars;
int main()
{
	for(int i = 0; i < 13; ++i)
	{
		MarsToEarth[Mars1[i]] = i;
		MarsToEarth[Mars2[i]] = i*13;
		EarthToMars[i*13] = Mars2[i];
		EarthToMars[i] = Mars1[i];
	}
	int N;
	scanf("%d", &N);
	getchar();
	string s;
	for(int i = 0; i < N; ++i)
	{
		getline(cin, s);
		if(s[0] > '9') {
			if(s.length() < 4) cout << MarsToEarth[s] << endl;
			else {
				string s1 = s.substr(0, 3), s2 = s.substr(4, 3);
				cout << MarsToEarth[s1] + MarsToEarth[s2] << endl;
			} 
		} else {
			int num = stoi(s);
			if(num > 12) {
				cout << EarthToMars[num/13*13];
				if(num % 13) cout << " " << EarthToMars[num%13];
				cout << endl;				
			} else {
				cout << EarthToMars[num] << endl;
			}

		}
	}
	return 0;
}
