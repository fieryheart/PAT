#include <iostream>
#include <algorithm>
using namespace std;
struct Cake{
	double amount, price, unit;
}cake[1010];
bool cmp(struct Cake q, struct Cake p)
{
	return q.unit > p.unit;
}
int main()
{
	int n, i, index = 0;
	double d, total, sum = 0.0;
	cin >> n >> d;
	for(i = 0; i < n; i++)
		scanf("%lf", &cake[i].amount);
	for(i = 0; i < n; i++)
		scanf("%lf", &cake[i].price);
	for(i = 0; i < n; i++)
		cake[i].unit = cake[i].price / cake[i].amount;
	sort(cake, cake+n, cmp);
	total = d;
	while(index < n && total > 0){
		if(total - cake[index].amount >= 0)
		{
			sum += cake[index].price;
			total -= cake[index].amount; 
		} else {
			sum += cake[index].unit * total;
			total = 0.0;
		}
		index++;
	}
	printf("%.2lf", sum);
	return 0;
}
