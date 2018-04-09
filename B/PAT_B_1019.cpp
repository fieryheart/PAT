#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;

bool cmp1(int p, int q){
	return p > q;
}

bool cmp2(int p, int q){
	return p < q;
}

string toString(int num){
	string s = "";
	int n[4];
	int i, start = 0;
	if(num >= 1000)
		start = 4;
	else if(num < 1000 && num >= 100)
		start = 3;
	else if(num < 100 && num > 10)
		start = 2;
	else
		start = 1;

	for (i = 0; i < 4; i++) {
		if (i < start) {
			n[i] = num % 10;
			num /= 10;
		} else {
			n[i] = 0;
		}
	}

	for (i = 3; i >= 0; i--)
		s += (n[i] + '0');

	return s;
}

int main()
{

	int num, small, big;
	cin >> num;

	int n[4];
	int i;

	do {
		int start = 0;
		if(num >= 1000)
			start = 4;
		else if(num < 1000 && num >= 100)
			start = 3;
		else if(num < 100 && num > 10)
			start = 2;
		else
			start = 1;

		for (i = 0; i < 4; i++) {
			if (i < start) {
				n[i] = num % 10;
				num /= 10;
			} else {
				n[i] = 0;
			}
		}

		if(n[0] == n[1] && n[1] == n[2] && n[2] == n[3]) {
			cout << n[3] << n[2] << n[1] << n[0] << " - " << n[3] << n[2] << n[1] << n[0] << " = " << "0000";
			return 0; 
		}

		sort(n, n+4, cmp1);
		small = 0;
		for (i = 0; i < 4; i++)
			small += n[i] * pow(10, i);
		
		sort(n, n+4, cmp2);
		big = 0;
		for (i = 0; i < 4; i++)
			big += n[i] * pow(10, i);

		num = big - small;

		cout << toString(big) << " - " << toString(small) << " = " << toString(num) << endl;

	} while(num != 6174);

	return 0;
}