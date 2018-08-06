#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
typedef struct Stu{
	long long id;
	int score, fr, ln, lr;
}stu;
vector<stu> area[110];
vector<stu> v;
bool cmp1(stu q, stu p)
{
	return q.score > p.score;
}
bool cmp2(stu q, stu p)
{
	return q.score != p.score ? q.score > p.score : q.id < p.id;
}
int main()
{
	int n,k,i,j;
	cin >> n;
	for(i = 1; i <= n; i++)
	{
		cin >> k;
		for(j = 0; j < k; j++)
		{
			stu s;
			scanf("%lld%d", &s.id, &s.score);
			s.ln = i; 
			area[i].push_back(s);
		}
		sort(area[i].begin(), area[i].end(), cmp1);
		area[i][0].lr = 1;
		for(j = 1; j < area[i].size(); j++)
			if(area[i][j].score != area[i][j-1].score) area[i][j].lr = j+1;
			else  area[i][j].lr = area[i][j-1].lr;
		for(j = 0; j < area[i].size(); j++)
			v.push_back(area[i][j]);
	}
	sort(v.begin(), v.end(), cmp2);
	v[0].fr = 1;
	for(i = 1; i < v.size(); i++)
		if(v[i].score != v[i-1].score) v[i].fr = i+1;
		else v[i].fr = v[i-1].fr;
	printf("%d\n", v.size());
	for(i = 0; i < v.size(); i++)
		printf("%013lld %d %d %d\n", v[i].id, v[i].fr, v[i].ln, v[i].lr);
	return 0;
}
