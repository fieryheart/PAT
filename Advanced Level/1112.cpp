#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char str[1010];
	int k;
	int ascii[256] = {0}, stuck[256] = {0}, output[256] = {0};
	cin >> k;
	getchar();
	scanf("%s", str);
	int len = strlen(str);
	char pre = '#';
	int cnt = 1;
	str[len] = '#';
	for(int i = 0; i <= len; i++)
	{
		if(str[i] == pre) {
			cnt++;
		} else {
			if(cnt % k != 0) {
				ascii[pre] = 1; 
			}
			cnt = 1;
		}
		if(i != len) stuck[str[i]] = (cnt % k == 0);
		pre = str[i];
	}
	for(int i = 0; i < len; i++) {
		if(ascii[str[i]] == 1)
			stuck[str[i]] == 0;
	}
	for(int i = 0; i < len; i++)
	{
		if(stuck[str[i]] == 1 && output[str[i]] == 0) {
			printf("%c", str[i]);
			output[str[i]] = 1;	
		}
	}
	printf("\n");
	for(int i = 0; i < len; i++)
	{
		printf("%c", str[i]);
		if(stuck[str[i]] == 1)
		{
			i += k-1;
		}
	}
	return 0;
}
