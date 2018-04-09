#include <iostream>
#include <string>

using namespace std;

int formatAge(string s) {

	int i;
	string s1 = "";
	for(i = 0; i < s.length(); i++)
		if(s[i] == '/')
			continue;
		else
			s1 += s[i];

	return stoi(s1);
}

int main()
{

	int n;
	cin >> n;

	int sy = 18140906,ey = 20140906;

	int per = 0, min = sy, max = ey;
	string name, str_age, minName, maxName;

	int i, age;
	for(i = 0; i < n; i++) {
		cin >> name >> str_age;

		age = formatAge(str_age);

		if(age < sy || age > ey)
			continue;
		else {
			if (age >= min) {
				minName = name;
				min = age;
			}
			if( age <= max) {
				maxName = name;
				max = age;
			}
			per++;
		}
	}

	cout << per;
	if(per != 0)
		cout << " " << maxName << " " << minName;


	return 0;
}