#include <iostream>
using namespace std;
long long gcd(long long x, long long y) {
	return y == 0 ? abs(x) : gcd(y, x % y);
}
long long toMin(long long &x, long long &y) {
	long long temp = gcd(x, y);
	x /= temp;
	y /= temp;
}
long long toAbs(long long &x, long long &y) {
	x = abs(x);
	y = abs(y);
}
void printPart(long long x, long long y) {
	if(y == 0) {
		printf("Inf");
		return ;	
	}
	bool flag = true;
	if((x < 0 && y > 0) || (x > 0 && y < 0)) flag = false;
	toAbs(x, y);
	toMin(x, y);
	long long integer = x / y, particle = x % y;
	if(flag == false) printf("(-");
	if(particle == 0) printf("%lld", integer);
	else {
		if(integer == 0) printf("%lld/%lld", x, y);
		else printf("%lld %lld/%lld", integer, particle, y);
	}
	if(flag == false) printf(")");
}
void print(long long a, long long b, long long c, long long d, char oper)
{
	printPart(a, b);
	printf(" %c ", oper);
	printPart(c, d);
	cout << " = ";
	switch(oper) {
		case '+':printPart(a*d+b*c, b*d);break;
		case '-':printPart(a*d-b*c, b*d);break;
		case '*':printPart(a*c, b*d);break;
		case '/':printPart(a*d, b*c);break;
	}
	printf("\n");
}
int main()
{
	long long a,b,c,d;
	scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
	print(a, b, c, d, '+');
	print(a, b, c, d, '-');
	print(a, b, c, d, '*');
	print(a, b, c, d, '/');
	return 0;
}
