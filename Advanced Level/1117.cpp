#include <iostream>
using namespace std;
int ride[1000000] = {0};
int main()
{
	int n, i, maxn = -1, num, E;
	cin >> n;
	for(i = 0; i < n; i++)
	{
		scanf("%d", &num);
		if(num > maxn) maxn = num;
		ride[num]++;
	}
	for(i = 1; i <= maxn; i++)
		ride[i] += ride[i-1];
	for(i = 0; i <= maxn; i++)
		if(n - ride[i] == i){
			cout << i << endl;
			E = i;	
		}
	cout << E;
	return 0;
}
