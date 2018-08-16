#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v, temp;
int dp[101] = {0};
int visit[10010][110] = {0};
bool cmp(int q, int p)
{
	return q > p;
}
int main()
{
	int n,m, i,j, num;
	cin >> n >> m;
	for(i = 0; i < n; i++){
		scanf("%d", &num);
		if(num > m) continue;
		v.push_back(num);	
	}
	sort(v.begin(), v.end(), cmp);
	for(i = 0; i < v.size(); i++)
	{
		for(j = m; j >= v[i]; j--)
		{
			if(dp[j] <= dp[j-v[i]] + v[i])
			{
				dp[j] = dp[j-v[i]] + v[i];
				visit[i][j] = 1;
			}
		}
	}
	int index = v.size()-1;
	if(dp[m] != m) printf("No Solution");
	else 
		while(m > 0)
		{
			if(visit[index][m] == 1) {
				m -= v[index];
				temp.push_back(v[index]);
			}
			index--;
		}
	for(i = 0; i < temp.size(); i++)
	{
		if(i != 0) printf(" ");
		printf("%d", temp[i]);
	}
	return 0;
}
