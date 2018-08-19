#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

typedef struct Stu{
	char name[15], id[15];
	int grade;
}Stu;
vector<Stu> v;
bool cmp(Stu q, Stu p)
{
	return q.grade > p.grade;
}
int main()
{
	int n;
	cin >> n;
	v.resize(n);
	for(int i = 0; i < n; i++)
	{
		Stu s;
		scanf("%s%s%d", s.name, s.id, &s.grade);
		v.push_back(s);
	}
	sort(v.begin(), v.end(), cmp);
	int l,h,flag = 0;
	cin >> l >> h;
	for(int i = 0; i < v.size(); i++)
		if(v[i].grade >= l && v[i].grade <= h){
			flag = 1;
			printf("%s %s\n", v[i].name, v[i].id);
		} else if(v[i].grade < l) break;
	if(flag == 0) printf("NONE");
	return 0; 
}
