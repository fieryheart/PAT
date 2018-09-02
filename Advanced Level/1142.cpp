#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> graph[210];
int main()
{
	int nv, ne, i, j, m, k, v, w;
	int count[210];
	cin >> nv >> ne;
	for(i = 0; i < ne; i++)
	{
		scanf("%d%d", &v, &w);
		graph[v].push_back(w);
		graph[w].push_back(v);
	}
	cin >> m;
	for(i = 0; i < m; i++)
	{
		scanf("%d", &k);
		int cnt = 0;
		vector<int> subset;
		fill(count, count+210, 0);
		for(j = 0; j < k; j++)
		{
			scanf("%d", &v);
			subset.push_back(v);
			count[v]++;
			for(w = 0; w < graph[v].size(); w++)
				count[graph[v][w]]++;
		}
		for(j = 0; j < 210; j++)
			if(count[j] >= k)
				cnt++;
		for(j = 0; j < subset.size(); j++)
			if(count[subset[j]] < k)
				cnt = 0;
		if(cnt == k) printf("Yes\n");
		else if(cnt > k) printf("Not Maximal\n");
		else printf("Not a Clique\n");
	}
	return 0;
}
