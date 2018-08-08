#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char str[100], c=' ';
	scanf("%s", str);
	int len = strlen(str);
	int i,j;
	for(i = 0; i < len; i++)
		if(i+2 > len-(i+1)*2) break;
	int d = len - (i+1)*2;
	for(j = 0; j < i; j++)
	{
		printf("%c", str[j]);
		for(int k = 0; k < d; k++) printf("%c", c);
		printf("%c\n", str[len-1-j]);
	}
	for(j = i; j <= len-1-i; j++)
		printf("%c", str[j]);
 	return 0;
}
