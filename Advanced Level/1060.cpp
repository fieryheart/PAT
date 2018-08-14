#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char a[10000], b[10000], c[10000], d[10000];
	int n, i;
	scanf("%d %s %s", &n, a, b);
	int pa = strlen(a), pb = strlen(b);
	for(i = 0; i < strlen(a); i++)
		if(a[i] == '.') pa = i;
	for(i = 0; i < strlen(b); i++)
		if(b[i] == '.') pb = i;
	int numa = 0, numb = 0;
	while(a[numa] == '0' || a[numa] == '.') numa++;
	while(b[numb] == '0' || b[numb] == '.') numb++;
	if(pa >= numa) pa = pa - numa;
	else pa = pa - numa + 1;
	if(pb >= numb) pb = pb - numb;
	else pb = pb - numb + 1;
	if(numa == strlen(a)) pa = 0;
	if(numb == strlen(b)) pb = 0;
	int indexa = 0, indexb = 0;
	while(indexa < n) {
		if(a[numa] != '.' && numa < strlen(a))
			c[indexa++] = a[numa];
		else if(numa >= strlen(a))
			c[indexa++] = '0';
		numa++;
	}
	while(indexb < n) {
		if(b[numb] != '.' && numb < strlen(b))
			d[indexb++] = b[numb];
		else if(numb >= strlen(b))
			d[indexb++] = '0';
		numb++;
	}
	if(strcmp(c, d) == 0 && pa == pb)
		printf("YES 0.%s*10^%d", c, pa);
	else
		printf("NO 0.%s*10^%d 0.%s*10^%d", c, pa, d, pb); 
	return 0;
}
