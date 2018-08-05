#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Windows{
	int endd = 8*60*60;
}windows[110];
typedef struct Customer{
	int arrival, dur;
}customer;
vector<customer> v;
bool cmp(customer q, customer p)
{
	return q.arrival < p.arrival;
}
int main()
{
	int n,k,i,j,cnt=0,hh,mm,ss,dur,wait=0;
	cin >> n >> k;
	for(i = 0;i < n; i++)
	{
		scanf("%d:%d:%d %d", &hh,&mm,&ss,&dur);
		if(hh >= 17 && ss >= 1) continue;
		v.push_back({3600*hh+60*mm+ss, dur*60});
	}
	sort(v.begin(), v.end(), cmp);
	for(i = 0; i < v.size(); i++)
	{
		int win = -1, min = 9999999;
		for(j = 0; j < k; j++) 
		{
			if(windows[j].endd < min)
			{
				min = windows[j].endd;
				win = j;
			}
		}
		if(windows[win].endd > v[i].arrival){
			wait += (windows[win].endd - v[i].arrival);
			windows[win].endd += v[i].dur;
		} else {
			windows[win].endd = v[i].arrival + v[i].dur;
		}
	}
	printf("%.1lf", wait*1.0/60.0/v.size());
	return 0;
}
