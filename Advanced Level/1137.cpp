#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
map<string, int> mapp;
typedef struct Stu{
	string name;
	int prog = -1, mid = -1, fin = -1, g = -1;
}stu;
vector<stu> v, ans;
bool cmp(stu q, stu p)
{
	return q.g != p.g ? q.g > p.g : q.name < p.name;
}
int main()
{
	int p, m, n, i, id = 1, prog, mid, fin;
	string name;
	v.resize(30010);
	cin >> p >> m >> n;
	for(i = 0; i < p; i++)
	{
		cin >> name >> prog;
		if(mapp[name] == 0) {
			mapp[name] = id;
			v[id].name = name;
			id++;
		}
		v[mapp[name]].prog = prog;
	}
	for(i = 0; i < m; i++)
	{
		cin >> name >> mid;
		if(mapp[name] == 0) {
			mapp[name] = id;
			v[id].name = name;
			id++;
		}
		v[mapp[name]].mid = mid;		
	}
	for(i = 0; i < n; i++)
	{
		cin >> name >> fin;
		if(mapp[name] == 0) {
			mapp[name] = id;
			v[id].name = name;
			id++;
		}
		v[mapp[name]].fin = fin;		
	}
	for(i = 1; i < id; i++)
		if(v[i].mid > v[i].fin) v[i].g = (int)(v[i].mid*0.4+v[i].fin*0.6+0.5);
		else v[i].g = v[i].fin;
	for(i = 1; i < id; i++)
		if(v[i].prog >= 200 && v[i].g >= 60 && v[i].g <= 100)
			ans.push_back(v[i]);
	sort(ans.begin(), ans.end(), cmp);
	for(i = 0; i < ans.size(); i++)
		cout << ans[i].name << " " << ans[i].prog << " " << ans[i].mid << " " << ans[i].fin << " " << ans[i].g << endl;
	return 0;
}
