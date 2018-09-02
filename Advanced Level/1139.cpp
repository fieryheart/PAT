#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
struct person {
	int gender;
	vector<int> relation;
}people[10010];
typedef struct Bridge{
	int v, w;
}bridge;
vector<bridge> brg[110];
map<int, bool> mapp, alive;
bool cmp(bridge q, bridge p)
{
	return q.v != p.v ? q.v < p.v : q.w < p.w;
}
int main()
{
	int n, m, i, j, l, k, v, w;
	string p1, p2;
	cin >> n >> m;
	for(i = 0; i < m; i++)
	{
		cin >> p1 >> p2;
		v = stoi(p1);
		w = stoi(p2);
		mapp[abs(v)*10000+abs(w)] = mapp[abs(w)*10000+abs(v)] = true;
		alive[abs(v)] = alive[abs(w)] = true;
		if(p1[0] != '-') people[abs(v)].gender = 1;
		if(p2[0] != '-') people[abs(w)].gender = 1;
		people[abs(v)].relation.push_back(abs(w));
		people[abs(w)].relation.push_back(abs(v));
	}
	cin >> k;
	for(i = 0; i < k; i++)
	{
		scanf("%d%d", &v, &w);
		v = abs(v);
		w = abs(w);
		for(j = 0; j < people[v].relation.size(); j++) {
			for(l = 0; l < people[w].relation.size(); l++) {
				if(people[v].relation[j] == w ||
					people[w].relation[l] == v) continue;
				if(mapp[people[v].relation[j]*10000+people[w].relation[l]] == true && 
					people[people[v].relation[j]].gender == people[v].gender &&
					people[people[w].relation[l]].gender == people[w].gender)
					brg[i].push_back({people[v].relation[j], people[w].relation[l]}); 
			}
		}
		sort(brg[i].begin(), brg[i].end(), cmp);
	}
	for(i = 0; i < k; i++)
	{
		cout << brg[i].size() << endl;
		for(j = 0; j < brg[i].size(); j++)
			printf("%04d %04d\n", brg[i][j].v, brg[i][j].w);
	}
	return 0;
}
