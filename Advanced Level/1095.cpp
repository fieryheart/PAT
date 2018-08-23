#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
map<string, int> mapp;
map<string, bool> mstop;
typedef struct Record{
	string name;
	int time;
	bool flag;
}record;
vector<record> temp, v;
bool cmp1(record q, record p)
{
	return q.name != p.name ? q.name < p.name : q.time < p.time;
}
bool cmp2(record q, record p)
{
	return q.time < p.time;
}
int main()
{
	int n,k,i,j,hh,mm,ss;
	char st[5];
	cin >> n >> k;
	for(i = 0; i < n; i++)
	{
		record r;
		cin >> r.name;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		r.time = hh*3600 + mm*60 + ss;
		scanf("%s", st);
		r.flag = st[0] == 'i' ? true : false;
		temp.push_back(r);
	}
	sort(temp.begin(), temp.end(),cmp1);
	for(i = 0; i < temp.size()-1; i++)
	{
		if(temp[i].name == temp[i+1].name && temp[i].flag == true && temp[i+1].flag == false){
			v.push_back(temp[i]);
			v.push_back(temp[i+1]);
		}
	}
	for(i = 0; i < v.size(); i += 2)
		mapp[v[i].name]	+= (v[i+1].time-v[i].time);
	sort(v.begin(), v.end(), cmp2);
	int time, cnt = 0, index = 0;
	for(i = 0; i < k; i++)
	{
		scanf("%d:%d:%d", &hh, &mm, &ss);
		time = hh*3600 + mm*60 + ss;
		for(j = index; j < v.size(); j++)
		{
			if(v[j].time <= time) {
				if(mstop[v[j].name] == false) {
					cnt++;
					mstop[v[j].name] = true;
				} else if(mstop[v[j].name] == true) {
					cnt--;
					mstop[v[j].name] = false;
				}
				index++;
			} else break;
			
		}
		cout << cnt << endl;
	}
	int maxt = -1;
	vector<string> vs;
	for(auto it = mapp.begin(); it != mapp.end(); it++)
		if(it->second > maxt) {
			maxt = it->second;
			vs.clear();
			vs.push_back(it->first);
		} else if(it->second == maxt) {
			vs.push_back(it->first);
		}
	for(i = 0; i < vs.size(); i++)
		cout << vs[i] << " ";
	printf("%02d:%02d:%02d", maxt/3600, maxt%3600/60, maxt%60);
	return 0;
}
