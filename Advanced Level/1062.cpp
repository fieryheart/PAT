#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct Stu{
	int id, vg, tg, total;
}Stu;
vector<Stu> v[4];
bool cmp(Stu q, Stu p)
{
	return q.total != p.total ? q.total > p.total : ( q.vg != p.vg ? q.vg > p.vg : q.id < p.id);
}
int main()
{
	int n, l, h, id, vg, tg, num = 0;
	cin >> n >> l >> h;
	for(int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &id, &vg, &tg);
		if(vg < l || tg < l) continue;
		else {
			Stu s;
			s.id = id;
			s.vg = vg;
			s.tg = tg;
			s.total = vg + tg;
			if(vg >= h && tg >= h) v[0].push_back(s);
			else if(vg >= h && tg < h) v[1].push_back(s);
			else if(vg < h && tg < h && vg >= tg) v[2].push_back(s);
			else v[3].push_back(s);
			num++;
		}
	}	
	for(int i = 0; i < 4; i++)
		sort(v[i].begin(), v[i].end(), cmp);	
	printf("%d\n", num);
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < v[i].size(); j++)
		{
			printf("%08d %d %d\n", v[i][j].id, v[i][j].vg, v[i][j].tg);
		}
	}
	return 0;
}
