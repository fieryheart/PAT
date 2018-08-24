#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Data{
	int id, fid, mid, estate, area;
	int cid[10];
}data[10010];
struct Family{
	int people, id;
	double estate, area;
	bool flag = false;
}family[10010];
int father[10010];
bool visit[10010] = {0};
int find(int x)
{
	while(x != father[x])
		x = father[x];
	return x;
}
void Union(int a, int b)
{
	int fa = find(a);
	int fb = find(b);
	
	if(fa > fb) {
		father[fa] = fb;
	} else if(fa < fb){
		father[fb] = fa;
	}
} 
bool cmp(struct Family q, struct Family p)
{
	if(q.area != p.area){
		return q.area > p.area;
	} else{
		return q.id < p.id;
	}
}
int main()
{
	int n, i, j, k;
	cin >> n;
	for(i = 0; i < 10000; i++)
		father[i] = i;
	for(i = 0; i < n; i++)
	{
		scanf("%d%d%d%d", &data[i].id, &data[i].fid, &data[i].mid, &k);
		visit[data[i].id] = true;
		if(data[i].fid != -1) {
			visit[data[i].fid] = true;
			Union(data[i].fid, data[i].id);
		}
		if(data[i].mid != -1) {
			visit[data[i].mid] = true;
			Union(data[i].mid, data[i].id);
		}
		for(j = 0; j < k; j++)
		{
			scanf("%d", &data[i].cid[j]);
			visit[data[i].cid[j]] = true;
			Union(data[i].cid[j], data[i].id);
		}
		scanf("%d%d", &data[i].estate, &data[i].area);
	}
	for(i = 0; i < n; i++)
	{
		int id = find(data[i].id);
		family[id].area += data[i].area;
		family[id].estate += data[i].estate;
		family[id].id = id;
		family[id].flag = true;
	}
	int ans = 0;
	for(i = 0; i < 10000; i++)
	{
		if(visit[i] == true)
			family[find(i)].people++;
		if(family[i].flag == true)
			ans++;
	}
	for(i = 0; i < 10000; i++)
	{
		if(family[i].flag == true){
			family[i].estate = family[i].estate / family[i].people;
			family[i].area = family[i].area / family[i].people;
		}
	}
	sort(family, family+10000, cmp);
	printf("%d\n", ans);
	for(i = 0; i < ans; i++)
		printf("%04d %d %.3lf %.3lf\n", family[i].id, family[i].people, family[i].estate,family[i].area);
	return 0;
}
