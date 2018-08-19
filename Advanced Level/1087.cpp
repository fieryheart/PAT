#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 9999999; 
int n, k, s, d, mpath=0, maxHappy = -1, avgHappy = -1;
int happy[210] = {0};
int graph[210][210];
map<string, int> mapp;
map<int, string> rmapp;
vector<int> pre[210];
vector<int> tempPath, path;
void dfs(int root, int sumHappy, int depth)
{
	tempPath.push_back(root);
	if(root == s) {
		mpath++;
		if(sumHappy > maxHappy) {
			maxHappy = sumHappy;
			avgHappy = sumHappy / (depth-1);
			path = tempPath;
		} else if(sumHappy == maxHappy) {
			if(sumHappy/depth > avgHappy) {
				avgHappy = sumHappy/(depth-1);
				path = tempPath;
			}
		}
		tempPath.pop_back();
		return ;
	}
	for(int i = 0; i < pre[root].size(); i++)
		dfs(pre[root][i], sumHappy+happy[pre[root][i]], depth+1);
	tempPath.pop_back();
}
void dijkstra()
{
	int dis[210], visit[210] = {0};
	fill(dis, dis+210, maxn);
	dis[s] = 0;
	while(true) {
		int v=-1, minn = maxn;
		for(int i = 1; i <= n; i++) {
			if(visit[i] == 0 && dis[i] < minn) {
				minn = dis[i];
				v = i;
			} 
		}
		if(v == -1) break;
		visit[v] = 1;
		for(int w = 1; w <= n; w++) {
			if(dis[w] > graph[v][w] + dis[v]) {
				dis[w] = graph[v][w] + dis[v];
				pre[w].clear();
				pre[w].push_back(v);
			} else if(graph[v][w] < maxn && dis[w] == graph[v][w] + dis[v]) {
				pre[w].push_back(v);
			}
		}
	}
	dfs(d, happy[d], 1);
	cout << mpath << " " << dis[d] << " " << maxHappy << " " << avgHappy << endl;
	for(int i = path.size()-1; i >= 0; i--) {
		if(i != path.size()-1) printf("->");
		cout << rmapp[path[i]];
	}
}
int main()
{
	string scity, city, v, w;
	int i,index = 1, hp;
	cin >> n >> k >> scity;
	mapp[scity] = index;
	rmapp[index] = scity;
	s = index;
	index++;
	for(i = 0; i < n-1; i++) {
		cin >> city >> hp;
		mapp[city] = index;
		rmapp[index] = city;
		if(city == "ROM") d = index;
		index++;
		happy[mapp[city]] = hp; 
	}
	fill(graph[0], graph[0]+210*210, maxn);
	for(i = 0; i < k; i++) {
		cin >> v >> w >> hp;
		graph[mapp[v]][mapp[w]] = graph[mapp[w]][mapp[v]] = hp; 
	}
	dijkstra();
	return 0;
}
