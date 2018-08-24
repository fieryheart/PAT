#include <iostream>
using namespace std;
long long gcd(long long q, long long p)
{
	long long maxn = max(q, p), minn = min(q, p), temp;
	if(minn == 0) return 1;
	while(maxn % minn != 0){
		temp = minn;
		minn = maxn % temp;
		maxn = temp;
	}
	return abs(minn);
}
void simplify(long long &q, long long &p)
{
	long long temp = gcd(q, p);
	q /= temp;
	p /= temp;
}
string pprint(long long q, long long p)
{
	if(p == 0) return "Inf";
	long long rn = q / p, rd = q % p;
//	cout << rn << " " << rd << endl;
	int flag = 0;
	if(q * p < 0) flag = 1; 
	string s = "";
	if(rn == 0 && rd != 0) {
		s = to_string(abs(q)) + "/" + to_string(abs(p));
		if(flag == 1) s = "(-" + s + ")";
	} else if(rd == 0){
		s = to_string(abs(rn));
		if(flag == 1) s = "(-" + s + ")"; 
	} else {
		s = to_string(abs(rn)) + " " + to_string(abs(rd)) + "/" + to_string(abs(p));
		if(flag == 1) s = "(-" + s + ")";
	}
	return s;
}
int main()
{
	long long a,b,c,d,rn,rd;
	scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
	simplify(a, b);
	simplify(c, d);
//	cout << "a: " << a << " b: " << b << " c: " << c << " d: " << d << endl;
	rn = a*d + b*c;
	rd = b*d;
//	cout << "rn: " << rn << " rd: " << rd << endl;
	simplify(rn, rd);
	cout << pprint(a,b) << " + " << pprint(c,d) << " = " << pprint(rn, rd) << endl;
	rn = a*d - b*c;
	rd = b*d;
	simplify(rn, rd);
//	cout << "rn: " << rn << " rd: " << rd << endl;
	cout << pprint(a,b) << " - " << pprint(c,d) << " = " << pprint(rn, rd) << endl;
	rn = a * c;
	rd = b * d;
	simplify(rn, rd);
	cout << pprint(a,b) << " * " << pprint(c,d) << " = " << pprint(rn, rd) << endl;
	if(c < 0) {
		c *= -1;
		d *= -1;	
	}
	rn = a*d;
	rd = b*c;
	simplify(rn, rd);
	cout << pprint(a,b) << " / " << pprint(c,d) << " = " << pprint(rn, rd) << endl;
	return 0;
}
