#include <iostream>
#include <vector>
using namespace std;
int n, m, q;
vector<int> graph[10010];
int main()
{
	int i, j, k, v, w, eNum = 0;
	cin >> n >> m;
	for(i = 0; i < m; i++)
	{
		scanf("%d%d", &v, &w);
		eNum++;
		graph[v].push_back(i);
		graph[w].push_back(i);
	}
	cin >> q;
	for(i = 0; i < q; i++)
	{
		scanf("%d", &k);
		int cnt = 0;
		vector<int> edge(m, 0);
		for(j = 0; j < k; j++)
		{
			scanf("%d", &v);
			for(w = 0; w < graph[v].size(); w++)
			{
				if(edge[graph[v][w]] == 0) {
					edge[graph[v][w]] = 1;
					cnt++;
				}
			}
		}
		if(cnt != eNum) cout << "No" << endl;
		else cout << "Yes" << endl;
	}
	return 0;
}
