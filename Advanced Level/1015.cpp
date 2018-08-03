#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int num)
{
	if(num == 1 || num == 0) return false;
	for(int i = 2; i*i <= num; i++)
		if(num%i==0) return false;
	return true;
}
int toReverseNum(int n, int d)
{
	string s = "";
	int rst = 0;
	while( n != 0){
		s += (n%d)+'0';
		n /= d;
	}
	int len = s.length();
	for(int i = len-1; i >= 0; i--)
		rst += (s[i]-'0')*pow(d, len-1-i);
	return rst;
}
int main()
{
	int n,d;
	while(cin >> n){
		if(n < 0) break;
		cin >> d;
		if(!isPrime(n)) {
			printf("No\n");
			continue;
		}
		if(isPrime(toReverseNum(n, d))) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
