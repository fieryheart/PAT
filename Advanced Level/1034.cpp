#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
struct person{
	int weight;
	vector<int> callto;
}person[10010];
typedef struct Gang{
	string head;
	int cnt;
}gang;
int visit[10010] = {0};
map<string, int> mapid;
map<int, string> mapname;
vector<gang> v;
int cnt, total, head, maxn = -1;
void dfs(int root)
{
	visit[root] = 1;
	cnt++;
	total += person[root].weight;
	if(person[root].weight > maxn)
	{
		maxn = person[root].weight;
		head = root;
	}
	for(int i = 0; i < person[root].callto.size(); i++)
		if(visit[person[root].callto[i]] == 0)
			dfs(person[root].callto[i]);
}
bool cmp(gang p, gang q)
{
	return p.head < q.head; 
}
int main()
{
	int n,k,i,index = 0, call;
	cin >> n >> k;
	string s1, s2;
	for(i = 0; i < n; i++)
	{
		cin >> s1 >> s2 >> call;
		if(mapid.find(s1) == mapid.end()) {
			mapid[s1] = index;
			mapname[index] = s1;
			index++;
		}
		if(mapid.find(s2) == mapid.end()) {
			mapid[s2] = index;
			mapname[index] = s2;
			index++;
		}
		person[mapid[s1]].weight += call;
		person[mapid[s2]].weight += call;
		person[mapid[s1]].callto.push_back(mapid[s2]);
		person[mapid[s2]].callto.push_back(mapid[s1]);
	}
	for(i = 0; i < index; i++)
	{
		if(visit[i] == 0) {
			cnt = 0;
			total = 0;
			head = 0;
			maxn = -1;
			dfs(i);
			if(cnt > 2 && total > k*2)
				v.push_back({mapname[head], cnt});
		}
	}
	if(v.size() == 0) {
		printf("0");
	} else {
		sort(v.begin(), v.end(), cmp);
		cout << v.size() << endl;
		for(i = 0; i < v.size(); i++)
			cout << v[i].head << " " << v[i].cnt << endl;
	}
	return 0;
}
