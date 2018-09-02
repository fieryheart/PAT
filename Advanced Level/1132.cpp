#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n, i, temp, number, t, x, y;
	cin >> n;
	for(i = 0; i < n; i++)
	{
		cin >> number;
		t = number;
		temp = 0;
		while(t != 0) {
			temp++;
			t /= 10;
		}
		x = number / (int)pow(10, temp/2);
		y = number % (int)pow(10, temp/2);
		if(x*y <= 0 || x*y > number || number % (x*y) != 0) cout << "No" << endl;
		else cout << "Yes" << endl;
	}
	return 0;
}
