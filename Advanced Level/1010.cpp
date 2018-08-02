#include <iostream>
#include <cmath>
using namespace std;
long long toNum(string s, long long radix)
{
	long long rst = 0;
	for(int i = s.length()-1; i>=0;i--)
	{
		int num = s[i] <= '9' ? s[i]-'0' : s[i]-'a'+10;
		rst += num*pow(radix, s.length()-1-i);
	}
	return rst;
}
int main()
{
	int tag;
	long long num, k;
	string n1,n2,n3;
	cin >> n1 >> n2 >> tag >> k;
	if(tag == 1) {
		n3 = n2;
		num = toNum(n1, k);
	} else {
		n3 = n1;
		num = toNum(n2, k);
	}
	char t = ' ';
	for(int i = 0; i < n3.length(); i++)
		if(n3[i] > t) t = n3[i];
	long long low = t <= '9' ? t-'0' : t-'a'+10;
	low += 1;
	long long high = max(num, low);
	long long radix = -1;
	while(low <= high){
		long long mid = (low+high)/2;
		long long nn = toNum(n3, mid);
		if(nn < 0 || nn > num) high = mid - 1;
		else if(nn == num){
			radix = mid;
			break;
		} else low = mid+1;
	}
	if(radix == -1) printf("Impossible");
	else printf("%lld", radix);
	return 0;
}
