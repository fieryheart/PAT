#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 999999999;
int graph[510][510], ttime[510][510];
vector<int> tempPath, path, spre[510], tpre[510], spath, tpath;
int n, m, s, d, sdis, tdis;
int minti = maxn;
void shortestdfs(int root, int ti)
{
	tempPath.push_back(root);
	if(root == s) {
		if(ti < minti) {
			minti = ti;
			path = tempPath;
		}
		tempPath.pop_back();
		return ;
	}
	for(int i = 0; i < spre[root].size(); i++)
		shortestdfs(spre[root][i], ti+ttime[spre[root][i]][root]);
	tempPath.pop_back();
}
void getShortestPath()
{
	int dis[510],visit[510] = {0};
	fill(dis, dis+510, maxn);
	dis[s] = 0;
	while(true) {
		int v = -1, minn = maxn;
		for(int i = 0; i < n; i++)
		{
			if(visit[i] == 0 && dis[i] < minn) {
				minn = dis[i];
				v = i;
			}
		}
		if(v == -1) break;
		visit[v] = 1;
		for(int w = 0; w < n; w++)
		{
			if(dis[w] > dis[v] + graph[v][w]) {
				dis[w] = dis[v] + graph[v][w];
				spre[w].clear();
				spre[w].push_back(v);
			} else if(dis[w] == dis[v] + graph[v][w])
				spre[w].push_back(v);
		}
	}
	path.clear();
	tempPath.clear();
	shortestdfs(d, 0);
	spath = path;
	sdis = dis[d];
}
int minno = maxn;
void fastestdfs(int root, int nnum)
{
	tempPath.push_back(root);
	if(root == s) {
		if(nnum < minno) {
			minno = nnum;
			path = tempPath;
		}
		tempPath.pop_back(); 
		return ;
	}
	for(int i = 0; i < tpre[root].size(); i++)
		fastestdfs(tpre[root][i], nnum+1);
	tempPath.pop_back();
}
void getFastestPath()
{
	int dis[510], visit[510] = {0};
	fill(dis, dis+510, maxn);
	dis[s] = 0;
	while(true) {
		int v = -1, minn = maxn;
		for(int i = 0; i < n; i++)
		{
			if(visit[i] == 0 && dis[i] < minn)
			{
				minn = dis[i];
				v = i;
			}
		}
		if(v == -1) break;
		visit[v] = 1;
		for(int w = 0; w < n; w++)
		{
			if(dis[w] > dis[v] + ttime[v][w])
			{
				dis[w] = dis[v] + ttime[v][w];
				tpre[w].clear();
				tpre[w].push_back(v);
			} else if(dis[w] == dis[v] + ttime[v][w])
				tpre[w].push_back(v);
		}
	}
	path.clear();
	tempPath.clear();
	fastestdfs(d, 1);
	tpath = path;
	tdis = dis[d];
}
int main()
{
	int i,v,w,ow,le,ti;
	cin >> n >> m;
	fill(graph[0], graph[0]+510*510, maxn);
	fill(ttime[0], ttime[0]+510*510, maxn); 
	for(i = 0; i < m; i++)
	{
		scanf("%d%d%d%d%d", &v, &w, &ow, &le, &ti);
		if(ow == 0) {
			graph[v][w] = graph[w][v] = le;
			ttime[v][w] = ttime[w][v] = ti;
		} else {
			graph[v][w] = le;
			ttime[v][w] = ti;
		}
	}
	cin >> s >> d;
	getShortestPath();
	getFastestPath();
	for(i = 0; i < spath.size(); i++)
		if(spath[i] != tpath[i]) break;
	if(i == spath.size()) {
		printf("Distance = %d; Time = %d: ", sdis, tdis);
		for(int i = spath.size()-1; i >= 0; i--)
		{
			printf("%d", spath[i]);
			if(i != 0) printf(" -> ");
		}		
	} else {
		printf("Distance = %d: ", sdis);
		for(int i = spath.size()-1; i >= 0; i--)
		{
			printf("%d", spath[i]);
			if(i != 0) printf(" -> ");
		}
		cout << endl;
		printf("Time = %d: ", tdis);
		for(int i = tpath.size()-1; i >= 0; i--)
		{
			printf("%d", tpath[i]);
			if(i != 0) printf(" -> ");
		}	
	}
	return 0;
}
