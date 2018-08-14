#include <iostream>
#include <map>
using namespace std;
map<int, int> mapp[55];
int main()
{
	int n, i, j, k, s, t, nc, nt, num;
	cin >> n;
	for(i = 1; i <= n; i++)
	{
		scanf("%d", &t);
		for(j = 0; j < t; j++)
		{
			scanf("%d", &num);
			mapp[i][num]++;
		}
	}
	cin >> n;
	for(i = 0; i < n; i++)
	{
		scanf("%d%d", &s, &t);
		nc = nt = 0;
		for(auto t1 = mapp[s].begin(); t1 != mapp[s].end(); t1++)
			if(mapp[t].find(t1->first) == mapp[t].end())
				nt++;
			else
				nc++;
		nt += mapp[t].size();
		printf("%.1lf%\n", nc*100.0/nt);
	}
	return 0;
}
