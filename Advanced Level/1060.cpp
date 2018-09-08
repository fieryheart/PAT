#include <iostream>
#include <cstring> 
using namespace std;
int main()
{
	char a[10000], b[10000], c[10000], d[10000];
	int n, i, az = 0, bz = 0, ap = 0, bp = 0, indexa, indexb, index;
	scanf("%d %s %s", &n, a, b);
	while(az < strlen(a) && (a[az] == '0' || a[az] == '.')) az++;
	while(bz < strlen(b) && (b[bz] == '0' || b[bz] == '.')) bz++;
	while(ap < strlen(a) && a[ap] != '.') ap++;
	while(bp < strlen(b) && b[bp] != '.') bp++;
	if(ap > az) indexa = ap - az;
	else indexa = -(az - ap - 1);
	if(bp > bz) indexb = bp - bz;
	else indexb = -(bz - bp - 1);
	if(az == strlen(a)) indexa = 0;
	if(bz == strlen(b)) indexb = 0;
	i = index = 0;
	while(index < n){
		if(az >= strlen(a)) c[index++] = '0';
		else if(a[az] != '.') c[index++] = a[az];
		az++;
	}
	i = index = 0;
	while(index < n){
		if(bz >= strlen(b)) d[index++] = '0';
		else if(b[bz] != '.') d[index++] = b[bz];
		bz++;
	}
	bool flag = true;
	if(indexa != indexb) flag = false;
	if(strcmp(c, d)) flag = false;
	if(flag) printf("YES 0.%s*10^%d", c, indexa);
	else printf("NO 0.%s*10^%d 0.%s*10^%d", c, indexa, d, indexb);
	return 0;
}
