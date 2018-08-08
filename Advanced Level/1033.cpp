#include <iostream>
#include <algorithm>
using namespace std;
struct Station{
	double dis, price;	
}station[510];
bool cmp(struct Station q, struct Station p)
{
	return q.dis < p.dis;
}
int main()
{
	int n, i, j;
	double cmax, d, davg;
	cin >> cmax >> d >> davg >> n;
	for(i = 0; i < n; i++)
		scanf("%lf%lf", &station[i].price, &station[i].dis);
	station[n].dis = d;
	station[n].price = 0.0;
	sort(station, station+n, cmp);
	if(station[0].dis > 0.0){
		printf("The maximum travel distance = 0.00");
		return 0;
	}
	int thisS = 0;
	double cost = 0.0, tank = 0.0, canDrive = 0.0;
	while(thisS < n)
	{
		if(canDrive + cmax*davg < station[thisS+1].dis) break;
		int toS = -1;
		double minn = 9999999.99;
		for(j = thisS+1; j < n && canDrive + cmax*davg >= station[j].dis; j++)
		{
			if(station[j].price < minn)
			{
				minn = station[j].price;
				toS = j;
				if(minn < station[thisS].price) break;
			}
		}
		if(toS == -1 || ((canDrive + cmax*davg) >= d && station[toS].price > station[thisS].price)) toS = n;
		if(station[toS].price < station[thisS].price) {
			if(tank * davg + station[thisS].dis >= station[toS].dis)
			{
				tank -= (station[toS].dis-station[thisS].dis) / davg;
			} else {
				cost += ((station[toS].dis-station[thisS].dis) / davg - tank) * station[thisS].price;
				tank = 0.0;
			}
		} else {
			cost += (cmax-tank)*station[thisS].price;
			tank = cmax - (station[toS].dis-station[thisS].dis) / davg;
		}
		thisS = toS;
		canDrive = station[toS].dis;
	}
	if(canDrive < d) printf("The maximum travel distance = %.2lf", canDrive+cmax*davg);
	else printf("%.2lf", cost);
	return 0;
}
