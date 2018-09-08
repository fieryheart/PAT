#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
typedef struct Station{
	double price, distance;
}station;
vector<station> v;
bool cmp(station q, station p)
{
	return q.distance < p.distance;
}
int main()
{
	double cmax, d, davg, tank = 0, maxDistance = 0, bill = 0.0;
	int n,i, thisStation = 0;
	cin >> cmax >> d >> davg >> n;
	for(i = 0; i < n; i++)
	{
		station s; 
		scanf("%lf %lf", &s.price, &s.distance);
		v.push_back(s);
	}
	sort(v.begin(), v.end(), cmp);
	v.push_back({0.0, d});
	if(v[0].distance > 0) {
		printf("The maximum travel distance = 0.00\n");
		return 0;
	}
	maxDistance = cmax * davg;
	while(thisStation < v.size()) 
	{
		int next = -1;
		for(i = thisStation; i < v.size() && v[i].distance <= v[thisStation].distance + maxDistance; i++)
		{
			if(v[i].price < v[thisStation].price) {
				next = i;
				break;
			}
		}
		if(next == -1) {
			double maxn= 99999999.9;
			for(i = thisStation+1; i < v.size() && v[i].distance <= v[thisStation].distance + maxDistance; i++)
			{
				if(v[i].price < maxn) {
					maxn = v[i].price;
					next = i;
				}
			}
			if(next == -1) {
				printf("The maximum travel distance = %.2lf\n", v[thisStation].distance+maxDistance);
				return 0;
			}
		}
		double need = (v[next].distance - v[thisStation].distance) / davg;
		if(v[next].price < v[thisStation].price) {
			if(tank < need) {
				bill += (need - tank) * v[thisStation].price;
				tank = 0;
			} else  tank -= need;
		} else {
			bill += (cmax - tank) * v[thisStation].price;
			tank = cmax - need;
		}
		thisStation = next;
		if(thisStation == v.size()-1) break;
	}
	printf("%.2lf\n", bill);
	return 0;
}
