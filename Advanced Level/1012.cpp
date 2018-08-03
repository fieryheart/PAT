#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef struct Stu{
	int id,A,C,M,E;
	int rank[4];
}stu;
vector<stu> v;
map<int, bool> mapp;
map<int, stu> student; 
bool cmpA(stu q, stu p)
{
	return q.A > p.A;
}
bool cmpC(stu q, stu p)
{
	return q.C > p.C;
}
bool cmpM(stu q, stu p)
{
	return q.M > p.M;
}
bool cmpE(stu q, stu p)
{
	return q.E > p.E;
}
int main()
{
	int n,m,i,j;
	cin >> n >> m;
	for(i = 0; i < n; i++)
	{
		stu s;
		scanf("%d%d%d%d", &s.id, &s.C, &s.M, &s.E);
		s.A = (s.C+s.M+s.E)/3;
		mapp[s.id] = true;
		v.push_back(s);
	}
	sort(v.begin(),v.end(),cmpA);
	v[0].rank[0] = 1;
	for(i = 1; i < v.size(); i++)
		if(v[i].A == v[i-1].A) v[i].rank[0] = v[i-1].rank[0];
		else v[i].rank[0] = i+1;
	sort(v.begin(),v.end(),cmpC);
	v[0].rank[1] = 1;
	for(i = 1; i < v.size(); i++)
		if(v[i].C == v[i-1].C) v[i].rank[1] = v[i-1].rank[1];
		else v[i].rank[1] = i+1;
	sort(v.begin(),v.end(),cmpM);
	v[0].rank[2] = 1;
	for(i = 1; i < v.size(); i++)
		if(v[i].M == v[i-1].M) v[i].rank[2] = v[i-1].rank[2];
		else v[i].rank[2] = i+1;
	sort(v.begin(),v.end(),cmpE);
	v[0].rank[3] = 1;
	for(i = 1; i < v.size(); i++)
		if(v[i].E == v[i-1].E) v[i].rank[3] = v[i-1].rank[3];
		else v[i].rank[3] = i+1;
	for(i = 0; i < v.size(); i++)
		student[v[i].id] = v[i];
	int id;
	int clas[4] = {'A', 'C', 'M', 'E'};
	for(i = 0; i < m; i++)
	{
		scanf("%d", &id);
		if(mapp[id] == false){
			printf("N/A\n");
		} else {
			int rank = 99999999, index = 0;
			for(j = 0; j < 4; j++) {
				if(student[id].rank[j] < rank){
					rank = student[id].rank[j];
					index = j;
				}
			}
			printf("%d %c\n", rank, clas[index]);
		}
	}
	return 0;
}
