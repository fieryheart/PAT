#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct Stu{
	int ge, gi, fg, id;
	vector<int> apply;
}stu;
struct School{
	int ge, fg, cap;
	vector<int> student;
}school[110];
vector<stu> v;
int n,m,k;
bool cmp(stu q, stu p)
{
	return q.fg != p.fg ? q.fg > p.fg : q.ge > p.ge; 
}
int main()
{
	int i,j,ge,gi,fg,ap;
	cin >> n >> m >> k;
	v.resize(n);
	for(i = 0; i < m; i++) scanf("%d", &school[i].cap);
	for(i = 0; i < n; i++) {
		scanf("%d%d", &v[i].ge, &v[i].gi);
		v[i].id = i;
		v[i].fg = (v[i].ge + v[i].gi);
		v[i].apply.resize(k);
		for(j = 0; j < k; j++) scanf("%d", &v[i].apply[j]);
	}
	sort(v.begin(), v.end(), cmp);
	for(i = 0; i < v.size(); i++)
	{
		for(j = 0; j < v[i].apply.size(); j++) {
			ap = v[i].apply[j];
			if(school[ap].cap > 0 || (v[i].fg == school[ap].fg && v[i].ge == school[ap].ge)) {
				school[ap].fg = v[i].fg;
				school[ap].ge = v[i].ge;
				school[ap].student.push_back(v[i].id);
				school[ap].cap--;
				break;
			}
		}
	}
	for(i = 0; i < m; i++) {
		sort(school[i].student.begin(), school[i].student.end());
		for(j = 0; j < school[i].student.size(); j++)
		{
			if(j != 0) printf(" ");
			printf("%d", school[i].student[j]);
		}
		printf("\n");
	}
	return 0;
}
