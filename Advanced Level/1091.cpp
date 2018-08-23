#include <iostream>
#include <queue>
using namespace std;
int graph[1300][130][70] = {0};
int visit[1300][130][70] = {0};
typedef struct Node{
	int l,m,n;
}node;
int dire[6][3] = {{-1,0,0},
				  {1,0,0},
				  {0,-1,0},
				  {0,1,0},
				  {0,0,-1},
				  {0,0,1}};
int main()
{
	int m,n,l,t,i,j,k;
	cin >> m >> n >> l >> t;
	for(i = 1; i <= l; i++)
		for(j = 1; j <= m; j++)
			for(k = 1; k <= n; k++)
				scanf("%d", &graph[j][k][i]);
	int ans = 0;
	int cnt, index = 0;
	node v;
	queue<node> q;
	for(i = 1; i <= l; i++)
		for(j = 1; j <= m; j++)
			for(k = 1; k <= n; k++)
				if(visit[j][k][i] == 0 && graph[j][k][i] == 1) {
					q.push({j,k,i});
					visit[j][k][i] = 1;
					cnt = 1;
					while(!q.empty()) {
						v = q.front();
						q.pop();	
						for(int i = 0; i < 6; i++)
						{
							if(visit[v.l+dire[i][0]][v.m+dire[i][1]][v.n+dire[i][2]] == 0 
							&& graph[v.l+dire[i][0]][v.m+dire[i][1]][v.n+dire[i][2]] == 1) 
							{
								visit[v.l+dire[i][0]][v.m+dire[i][1]][v.n+dire[i][2]] = 1;
								q.push({v.l+dire[i][0], v.m+dire[i][1], v.n+dire[i][2]});
								cnt++;
							}
						}
					}
					if(cnt >= t) ans += cnt;
				}
	cout << ans;
	return 0;
}
