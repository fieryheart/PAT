#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
struct Record{
	int id;
	double estate, area;
}record[1010];
struct family {
	int id, people = 0;
	double estate = 0.0, area = 0.0;
};
map<int, struct family> mapp;
map<int, bool> alive, isFamily;
vector<int> v;
int father[10010];
int find(int x)
{
	while(x != father[x])
		x = father[x];
	return x;	
}
void Union(int x, int y)
{
	x = find(x);
	y = find(y);
	father[max(x, y)] = min(x, y);
}
bool cmp(int q, int p)
{
	return mapp[q].area != mapp[p].area ? mapp[q].area > mapp[p].area : mapp[q].id < mapp[p].id;
}
int main ()
{
	int n, i, j, k, id, fid, mid, cid;
	cin >> n;
	for(i = 0; i < 10000; i++)
		father[i] = i;
	for(i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &id, &fid, &mid, &k);
		alive[id] = true;
		if(fid != -1) {
			Union(fid, id);	
			alive[fid] = true;
		}
		if(mid != -1){
			Union(mid, id);	
			alive[mid] = true;
		}
		record[i].id = id;
		for(j = 0; j < k; j++) {
			scanf("%d", &cid);
			Union(id, cid);
			alive[cid] = true;
		}
		scanf("%lf%lf", &record[i].estate, &record[i].area);
	}
	for(i = 0; i < n; i++)
	{
		int id = find(record[i].id);
		mapp[id].id = id;
		mapp[id].estate += record[i].estate;
		mapp[id].area += record[i].area;
		isFamily[id] = true;
	}
	for(i = 0; i < 10000; i++){
		if(alive[i] == true) mapp[find(i)].people++;
		if(isFamily[i] == true) v.push_back(i);	
	}
    for(int i = 0; i < v.size(); i++) {
        mapp[v[i]].estate = mapp[v[i]].estate / mapp[v[i]].people;
        mapp[v[i]].area = mapp[v[i]].area / mapp[v[i]].people;
    }
    sort(v.begin(), v.end(), cmp);
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++)
        printf("%04d %d %.3f %.3f\n", mapp[v[i]].id, mapp[v[i]].people, mapp[v[i]].estate, mapp[v[i]].area);
	return 0;
}
