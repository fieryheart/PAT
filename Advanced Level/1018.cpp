#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 99999999;
int graph[510][510];
int bikes[510]={0};
int cmax,n,sp,m;
vector<int> pre[510];
vector<int> path, tempPath;
int minNeed = 9999999, minBack = 9999999;
void dfs(int root)
{
	
	tempPath.push_back(root);
	if(root == 0) {
		int need = 0, back = 0;
		for(int i = tempPath.size()-1; i >= 0; i--)
		{
			int id = tempPath[i];
			if(bikes[id] >= 0)
			{
				back += bikes[id];
			} else {
				if(back >= -bikes[id]) {
					back += bikes[id];
				}else {
					need += -bikes[id]-back;
					back = 0;
				}
			}
		}
		if(need < minNeed) {
			minNeed = need;
			minBack = back;
			path = tempPath;
		} else if(need == minNeed) {
			if(back < minBack) {
				minBack = back;
				path = tempPath;
			}
		}
		tempPath.pop_back();
		return;
	}
	for(int i = 0; i < pre[root].size(); i++)
		dfs(pre[root][i]);
	tempPath.pop_back();
}
void dijkstra()
{
	int dis[510],visit[510]={0};
	fill(dis,dis+510,maxn);
	dis[0]=0;
	while(true)
	{
		int v=-1, min=maxn, i;
		for(i = 0; i <= n; i++)
		{
			if(visit[i] == 0 && dis[i] < min)
			{
				min = dis[i];
				v = i;
			}
		}
		if(v==-1)break;
		visit[v] = 1;
		for(i = 0; i <= n; i++)
		{
			if(graph[v][i] + dis[v] < dis[i]) {
				dis[i] = graph[v][i] + dis[v];
				pre[i].clear();
				pre[i].push_back(v);
			} else if(graph[v][i] + dis[v] == dis[i]) {
				pre[i].push_back(v);
			}
 		}
	}
	dfs(sp);
	printf("%d ", minNeed);
	for(int i = path.size()-1 ; i >= 0; i--)
	{
		printf("%d", path[i]);
		if(i != 0) printf("->");
	}
	printf(" %d", minBack);
}
int main()
{
	int i,j,v,w,t;
	cin >> cmax >> n >> sp >> m;
	bikes[0] = 0;
	for(i = 1; i <= n; i++){
		scanf("%d", &bikes[i]);
		bikes[i] = bikes[i]-cmax/2;
	}
	fill(graph[0], graph[0]+510*510, maxn);
	for(i = 0; i < m; i++)
	{
		scanf("%d%d%d", &v, &w, &t);
		graph[v][w] = graph[w][v] = t;
	}
	dijkstra();
	return 0;
}
