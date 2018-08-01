#include <iostream>
#include <algorithm>
using namespace std;
double poly[1010];
int main()
{
	int k,n;
	double a;
	cin >> k;
	fill(poly, poly+1010, 0.0);
	for(int i = 0; i < k; i++)
	{
		scanf("%d%lf", &n, &a);
		poly[n] += a;
	}
	cin >> k;
	for(int i = 0; i < k; i++)
	{
		scanf("%d%lf", &n, &a);
		poly[n] += a;		
	}
	int cnt = 0;
	for(int i = 1001; i >= 0; i--)
		if(poly[i] != 0) cnt++;
	cout << cnt;
	for(int i = 1001; i >= 0; i--)
		if(poly[i] != 0)
			printf(" %d %.1lf", i, poly[i]);
	return 0;
}
