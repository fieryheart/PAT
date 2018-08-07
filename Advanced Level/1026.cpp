#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Table{
	int cnt, endd=8*3600;
	bool tag;
}table[110];
struct Player{
	int arrival, server=99999999,dur;
	bool tag=false;
};
int n,k,m;
vector<struct Player> player;
bool cmp1(struct Player p, struct Player q)
{
	return p.arrival < q.arrival;
}
bool cmp2(struct Player p, struct Player q)
{
	return p.server < q.server;
}
int findNextVip(int last)
{
	int id = last+1;
	while(id < n && player[id].tag != true) id++;
	return id;
}
void doPlay(int p, int tab)
{
	if(player[p].arrival > table[tab].endd)
		player[p].server = player[p].arrival;
	else
		player[p].server = table[tab].endd;
	table[tab].endd = player[p].server + player[p].dur;
	table[tab].cnt++;
}
int main()
{
	int id,i,j,hh,mm,ss,dur,tag, cnt = 0;
	cin >> n;
	for(i = 0; i < n; i++)
	{
		struct Player p;
		scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &dur, &tag);
		p.arrival = hh*3600+mm*60+ss;
		if(p.arrival >= 21*3600) continue;
		p.dur = dur > 120 ? 7200 : dur*60;
		if(tag == 1) p.tag = true;
		if(tag == 0) p.tag = false;
		player.push_back(p);
	}
	cin >> k >> m;
	for(i = 0; i < m; i++)
	{
		scanf("%d", &id);
		table[id].tag = true;
	}
	sort(player.begin(), player.end(),cmp1);
	int vip = -1;
	vip = findNextVip(vip);
	for(i = 0; i < player.size(); i++)
	{
		int tab,minn = 9999999;
		for(j = 1; j <= k; j++)
		{
			if(table[j].endd < minn)
			{
				minn = table[j].endd;
				tab = j;
			}
		}
		if(table[tab].endd >= 21*3600) break;
		if(player[i].tag == true && i < vip) continue;
		if(table[tab].tag == false) {
			if(player[i].tag == false) {
				doPlay(i, tab);
			} else {
				int viptable = -1, minn = 9999999;
				for(j = 1; j <= k; j++)
				{
					if(table[j].tag == true && table[j].endd < minn)
					{
						minn = table[j].endd;
						viptable = j;
					}
				}
				if(viptable != -1 && table[viptable].endd <= player[i].arrival)
				{
					doPlay(i, viptable);
					if(vip == i)
					vip = findNextVip(i);
				} else {
					doPlay(i, tab);
					if(vip == i)
					vip = findNextVip(i);
				}
			}
		} else {
			if(player[i].tag == true) {
				doPlay(i, tab);
				if(vip == i)
				vip = findNextVip(i);
			} else {
				if(vip < n && player[vip].arrival <= table[tab].endd) {
					doPlay(vip, tab);
					vip = findNextVip(vip);
					i--;
				} else {
					doPlay(i, tab);
				}
			}
		}
	}
	sort(player.begin(), player.end(), cmp2);
	for(i = 0; i < player.size(); i++)
	{
		if(player[i].server < 21*3600)
		printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", player[i].arrival/3600, player[i].arrival%3600/60, player[i].arrival%60,
													player[i].server/3600, player[i].server%3600/60, player[i].server%60,
													(int)((player[i].server-player[i].arrival)/60.0+0.5));
	}
	for(i = 1; i <= k; i++)
	{
		if(i != 1) printf(" ");
		printf("%d", table[i].cnt);
	}
	return 0;
}
