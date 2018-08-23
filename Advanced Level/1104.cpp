#include <iostream>
using namespace std;
double seq[100010];
int main()
{
	int n,i;
	double ans = 0.0;
	cin >> n;
	for(i = 0;i < n; i++)
		scanf("%lf", &seq[i]);
	for(i = 0;i < n; i++)
		ans += seq[i]*(n-i)*(i+1);
	printf("%.2lf", ans);
	return 0;
}
