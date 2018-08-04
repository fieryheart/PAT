#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
struct Record{
	string name;
	int month, day, hour, minute, time;
	bool flag;
};
struct Record record[1010];
map< string, vector<struct Record> > mapp;
int bill[24];
int n, dayBill = 0;
bool cmp1(struct Record q, struct Record p)
{
	return q.name != p.name ? q.name < p.name : q.time < p.time;
}
double getBill(struct Record q) {
	int money = 0;
	money += dayBill * q.day;
	for(int i = 0; i < q.hour; i++) money += 60*bill[i];
	money += q.minute * bill[q.hour];
	return money/100.0;
}
int main()
{
	int i, j;
	char status[10];
	for(i = 0; i < 24; i++){
		scanf("%d", &bill[i]);
		dayBill += bill[i]*60;	
	}
	cin >> n;
	for(i = 0; i < n; i++)
	{
		cin >> record[i].name;
		scanf("%d:%d:%d:%d %s", &record[i].month, &record[i].day, &record[i].hour, &record[i].minute, status);
		record[i].time = record[i].day*60*24 + record[i].hour*60 + record[i].minute;
		if(status[1] == 'n') record[i].flag = true;
		if(status[1] == 'f') record[i].flag = false;
	}
	sort(record, record+n, cmp1);
//	for(i = 0; i < n; i++)
//		cout << record[i].name << " " << record[i].time << " " << record[i].flag << endl;
	for(i = 1; i < n; i++)
	{
		if(record[i].name == record[i-1].name && record[i-1].flag == true && record[i].flag == false) {
			mapp[record[i-1].name].push_back(record[i-1]);
			mapp[record[i].name].push_back(record[i]);
		}
	}
//	for(auto it = mapp.begin(); it != mapp.end(); it++)
//		for(j = 0; j < it->second.size(); j++)
//			cout << it->second[j].name << " " << it->second[j].time << " " << it->second[j].flag << endl;
	for(auto it = mapp.begin(); it != mapp.end(); it++)
	{
		double amount = 0.0;
		int month = it->second[0].month;
		cout << it->first;
		printf(" %02d\n", month);
		for(i = 0; i < it->second.size(); i+=2){
			double money = getBill(it->second[i+1]) - getBill(it->second[i]);
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n", it->second[i].day, it->second[i].hour, it->second[i].minute, 
																it->second[i+1].day, it->second[i+1].hour, it->second[i+1].minute,
																it->second[i+1].time-it->second[i].time, money);
			amount += money;
		}
		printf("Total amount: $%.2lf\n", amount);
	}
	return 0;
}
