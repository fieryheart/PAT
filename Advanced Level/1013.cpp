#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct City{
	vector<int> c;
}city[1010];
int visit[1010] = {0};
int n,m,k;
int bfs(int lost) {
	queue<int> q;
	int cnt = -1, i;
	visit[lost] = 1;
	while(true) {
		int v = -1;
		for(i = 1; i <= n; i++)
		{
			if(visit[i] == 0) {
				cnt++;
				v = i;
				break;
			}
		}
		if(v == -1) return cnt;
		q.push(v);
		while(!q.empty())
		{
			int w = q.front();
			visit[w] = 1;
			q.pop();
			for(i = 0; i < city[w].c.size(); i++)
				if(visit[city[w].c[i]] == 0){
					visit[city[w].c[i]] = 1;
					q.push(city[w].c[i]);
				}		
		}	
	}
}
int main()
{
	int i,j,v,w;
	cin >> n >> m >> k;
	for(i = 0; i < m; i++)
	{
		scanf("%d%d", &v, &w);
		city[v].c.push_back(w);
		city[w].c.push_back(v);
	}
	int lost; 
	for(i = 0; i < k; i++)
	{
		int cnt = 0;
		scanf("%d", &lost);
		fill(visit, visit+n+1, 0);
		cnt = bfs(lost);
		printf("%d\n", cnt);
	} 
	return 0;
}
