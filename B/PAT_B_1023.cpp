#include <iostream>
#include <string>

using namespace std;

int main()
{

	// int num[10] = {0};
	// 
	// 
	
	int num[10] = {0};
	int n, i;

	for (i = 0; i < 10; i++)
		cin >> num[i];


	int min = 0;
	for(i = 1; i < 10; i++) {
		if(num[i] != 0) {
			min = i;
			break;
		}
	}


	string str = "";
	str += (min + '0');
	num[i]--;


	int j;
	for(i = 0; i < 10; i++)
		for(j = 0; j < num[i]; j++)
			str += (i + '0');


	cout << str;

	return 0;
}