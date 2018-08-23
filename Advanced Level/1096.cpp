#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
	int n, i, j, t, s = 0, len = 0;
	cin >> n;
	t = n;
	vector<int> temp,v;
	int maxn = sqrt(n);
	for(i = 2; i <= maxn; i++) 
	{
		int temp = 1;
		for(j = i; j <= maxn; j++)
		{
			temp *= j;
			if(n % temp != 0) break;
		}
		if(j - i > len) {
			len = j-i;
			s = i;
		}
	}
	if(s <= 1) cout << 1 << endl << n;
	else {
		cout << len << endl;
		for(i = s; i < s+len; i++)
		{
			if(i != s) cout << "*";
			cout << i;
		}		
	}
	return 0;
}
