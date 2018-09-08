#include <iostream>
using namespace std;
long long gcd(long long a, long long b) {
	return b == 0 ? abs(a) : gcd(b, a % b);
}
int main()
{
	int n, i;
	long long a,b,c,d,temp;
	cin >> n;
	scanf("%lld/%lld", &a, &b);
	for(i = 1; i < n; i++)
	{
		scanf("%lld/%lld", &c, &d);
		a = a*d+b*c;
		b = b*d;
		temp = gcd(a, b);
		a /= temp;
		b /= temp;
	}
	long long integer = a / b, particle = a % b;
	if(particle == 0) printf("%lld", integer);
	else {
		if(integer == 0) printf("%lld/%lld", a, b);
		else printf("%lld %lld/%lld", integer, abs(particle), abs(b));
	}
	return 0;
}
