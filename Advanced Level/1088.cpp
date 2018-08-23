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
	long long rn = q / p, rd = q % p;
//	cout << rn << " " << rd << endl;
	string s = "";
	if(rn == 0 && rd != 0) {
		s = to_string(q) + "/" + to_string(p);
		if(q < 0) s = "(" + s + ")";
	} else if(rd == 0){
		s = to_string(rn);
		if(rn < 0) s = "(" + s + ")"; 
	} else {
		s = to_string(rn) + " " + to_string(abs(rd)) + "/" + to_string(abs(p));
		if(rn < 0) s = "(" + s + ")";
	}
	return s;
}
int main()
{
	long long a,b,c,d,temp,rn,rd;
	scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
	simplify(a, b);
	simplify(c, d);
	temp = b*d/gcd(b, d);
//	cout << "a: " << a << " b: " << b << " c: " << c << " d: " << d << endl;
	rn = a*temp/b + c*temp/d;
	rd = temp;
//	cout << "rn: " << rn << " rd: " << rd << endl;
	simplify(rn, rd);
	cout << pprint(a,b) << " + " << pprint(c,d) << " = " << pprint(rn, rd) << endl;
	rn = a*temp/b - c*temp/d;
	rd = temp;
	simplify(rn, rd);
//	cout << "rn: " << rn << " rd: " << rd << endl;
	cout << pprint(a,b) << " - " << pprint(c,d) << " = " << pprint(rn, rd) << endl;
	rn = a * c;
	rd = b * d;
	simplify(rn, rd);
	cout << pprint(a,b) << " * " << pprint(c,d) << " = " << pprint(rn, rd) << endl;
	if(c == 0) cout << pprint(a,b) << " / " << pprint(c,d) << " = " << "Inf" << endl;
	else {
		if(c < 0) {
			c *= -1;
			d *= -1;	
		}
		rn = a*d;
		rd = b*c;
		simplify(rn, rd);
		cout << pprint(a,b) << " / " << pprint(c,d) << " = " << pprint(rn, rd) << endl;
	}
	return 0;
}
