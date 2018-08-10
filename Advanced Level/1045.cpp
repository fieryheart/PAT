#include <iostream>
#include <vector>
using namespace std;
int number[210] = {0}, seq[100010], dp[100010];
int main()
{
	int n, m, l, i, j, num;
	cin >> n >> m;
	for(i = 1; i <= m; i++)
	{
		scanf("%d", &num);
		number[num] = i;
	}
	int cnt = 0, maxn = -1;
	cin >> l;
	for(i = 0; i < l; i++)
	{
		scanf("%d", &num);
		if(number[num] > 0) seq[cnt++] = number[num];
	}
	for(i = 0; i < cnt; i++)
	{
		dp[i] = 1;
		for(j = 0; j < i; j++)
			if(seq[j] <= seq[i])
				dp[i] = max(dp[i], dp[j]+1);
		if(dp[i] > maxn) maxn = dp[i];
	}
	cout << maxn;
	return 0;
}
