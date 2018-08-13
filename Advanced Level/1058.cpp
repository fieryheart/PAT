#include <iostream>
using namespace std;
int main()
{
	int g,s,k,g1,s1,k1,g2,s2,k2,carry=0;
	scanf("%d.%d.%d %d.%d.%d", &g1, &s1, &k1, &g2,&s2,&k2);
	k = (k1+k2) % 29;
	carry = (k1+k2)/29;
	s = (carry+s1+s2) % 17;
	carry = (carry+s1+s2) / 17;
	g = carry + g1 + g2;
	printf("%d.%d.%d", g, s, k);
	return 0;
}
