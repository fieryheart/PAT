#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int main()
{
	int n, sum = 0;
	cin >> n;
	v.resize(n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &v[i]);
		sum += v[i];
	}
	sort(v.begin(), v.end());
	int s2 = 0;
	for(int i = 0; i < n/2; i++)
		s2 += v[i];
	cout << (n+1)/2 - n/2 << " " << sum - 2*s2;
	return 0;
 } 
