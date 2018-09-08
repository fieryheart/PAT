#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct Record record;
struct Record{
	string name;
	int time, mon, dd, hh, mm;
	bool flag;
}rcd[1010];
vector<record> v;
int rate[25], total = 0;
bool cmp(record q, record p)
{
	return q.name != p.name ? q.name < p.name : q.time < p.time;
}
double getMoney(record r)
{
	int dd = r.dd, hh = r.hh, mm = r.mm;
	double ans = 0.0;
	ans += dd * total * 60;
	for(int i = 0; i < hh; i++)
		ans += rate[i]*60;
	ans += mm * rate[hh];
	return ans / 100.0;	
}
int main()
{
	int n, i;
	char statue[10];
	for(i = 0; i < 24; i++){
		scanf("%d", &rate[i]);
		total += rate[i];	
	}
	cin >> n;
	for(i = 0; i < n; i++)
	{
		cin >> rcd[i].name;
		scanf("%d:%d:%d:%d %s", &rcd[i].mon, &rcd[i].dd, &rcd[i].hh, &rcd[i].mm, statue);
		rcd[i].time = rcd[i].dd*24*60 + rcd[i].hh*60 + rcd[i].mm;
		if(statue[1] == 'n') rcd[i].flag = true;
		else rcd[i].flag = false;
	}
	sort(rcd, rcd+n, cmp);
//	for(i = 0; i < n; i++)
//		cout << rcd[i].name << " " << rcd[i].time << " " << rcd[i].flag << endl;
	for(i = 0; i < n-1; i++)
		if(rcd[i].name == rcd[i+1].name && rcd[i].flag == 1 && rcd[i+1].flag == 0)
		{
			v.push_back(rcd[i]);
			v.push_back(rcd[i+1]);
		}
//	for(i = 0; i < v.size(); i++)
//		cout << v[i].name << " " << v[i].time << " " << v[i].flag << endl;
	string name = "";
	double ans = 0;
	for(i = 0; i < v.size(); i+=2)
	{
		if(v[i].name != name) {
			if(i != 0)printf("Total amount: $%.2lf\n", ans);
			cout << v[i].name;
			printf(" %02d\n", v[i].mon);
			name = v[i].name;
			ans = 0.0;
		}
		double fee = getMoney(v[i+1]) - getMoney(v[i]);
		ans += fee;
		printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n", v[i].dd, v[i].hh, v[i].mm, v[i+1].dd, v[i+1].hh, v[i+1].mm, v[i+1].time-v[i].time, fee);
	}
	printf("Total amount: $%.2lf\n", ans);
	return 0;
}
