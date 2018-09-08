#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n, i, j, maxl = 0, start = -1, maxn;
	cin >> n;
	maxn = sqrt(n);
	for(i = 2; i <= maxn; i++)
	{
		int temp = n;
		for(j = i; j <= maxn; j++)
		{
			if(temp % j != 0) break;
			temp /= j;
		}
		if(j - i > maxl) {
			start = i;
			maxl = j - i;
		}
	}
	if(start <= 1) cout << 1 << endl << n;
	else {
		cout << maxl << endl;
		for(i = start; i < start+maxl; i++)
		{
			if(i != start) printf("*");
			printf("%d", i);
		}	
	}
	return 0;
}
