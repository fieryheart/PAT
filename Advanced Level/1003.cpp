#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 99999999;
int graph[510][510];
int rescues[510];
vector<int> pre[510];
int n, m, startt, endd, maxTeam=-1, path = 0;
void dfs(int w, int team)
{
	if(w == startt){
		path++;
		if(team+rescues[w] > maxTeam) maxTeam = team+rescues[w];
	}
	for(int i = 0; i < pre[w].size(); i++)
		dfs(pre[w][i], team+rescues[w]);
}
void dijkstra(int s)
{
	int visit[510] = {0}, dis[510];
	fill(dis, dis+510, maxn);
	dis[s] = 0;
	while(true){
		int v=-1, i, min = maxn;
		for(i = 0; i < n; i++)
		{
			if(visit[i] == 0 && dis[i] < min) {
				min = dis[i];
				v = i;
			}
		}
		if(v == -1) break;
		visit[v] = 1;
		for(i = 0; i < n; i++) {
			if(dis[i] > dis[v] + graph[v][i])
			{
				dis[i] = dis[v] + graph[v][i];
				pre[i].clear();
				pre[i].push_back(v);
			} else if (dis[i] == dis[v] + graph[v][i])
			{
				pre[i].push_back(v);	
			} 
		}
	}
	dfs(endd, 0);
}
int main()
{
	int i,j,v,w,d;
	cin >> n >> m >> startt >> endd;
	fill(graph[0], graph[0]+510*510, maxn);
	for(i = 0; i < n; i++)
		scanf("%d", &rescues[i]);
	for(i = 0; i < m; i++)
	{
		scanf("%d%d%d", &v, &w, &d);
		graph[v][w] = graph[w][v] = d;
	}
	dijkstra(startt);
	cout << path << " " << maxTeam;
	return 0;
}
