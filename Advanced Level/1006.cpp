#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct Record
{
	char name[20];
	int in,out;
}record;
vector<record> v;
bool cmp1(record q, record p)
{
	return q.in < p.in;
}
bool cmp2(record q, record p)
{
	return q.out > p.out;
}
int main()
{
	int n, hh, mm, ss;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		record r;
		scanf("%s", r.name);
		scanf("%d:%d:%d", &hh, &mm, &ss);
		r.in = 3600*hh + 60*mm + ss;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		r.out = 3600*hh + 60*mm + ss;
		v.push_back(r);
	}
	sort(v.begin(), v.end(), cmp1);
	printf("%s ", v[0].name);
	sort(v.begin(), v.end(), cmp2);
	printf("%s", v[0].name);
	return 0;
}
