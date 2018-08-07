#include <iostream>
#include <string.h> 
#include <vector>
#include <algorithm>
using namespace std;
typedef struct stu {
	int id,grade;
	char name[10];
}stu;
vector<stu> v;
bool cmp1(stu p, stu q)
{
	return p.id < q.id;
}
bool cmp2(stu p, stu q)
{
	return strcmp(p.name, q.name) != 0 ? strcmp(p.name, q.name) < 0 : p.id < q.id;
}
bool cmp3(stu p, stu q)
{
	return p.grade != q.grade ? p.grade < q.grade : p.id < q.id;
}
int main()
{
	int n, c, i;
	cin >> n >> c;
	for(i = 0; i < n; i++)
	{
		stu s;
		scanf("%d%s", &s.id, s.name);
		scanf("%d", &s.grade);
		v.push_back(s);
	}
	if(c == 1) sort(v.begin(), v.end(), cmp1);
	if(c == 2) sort(v.begin(), v.end(), cmp2);
	if(c == 3) sort(v.begin(), v.end(), cmp3);
	for(i = 0; i < n; i++)
	{
		printf("%06d %s", v[i].id, v[i].name);
		printf(" %d\n", v[i].grade);
	}
	return 0;
}
