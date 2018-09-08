#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int p, i, indexb = 0, index;
	string s = "";
	char a[100010], b[100010];
	scanf("%s", a);
	for(i = 1; i < strlen(a); i++)
	{
		if(a[i] == '.') {
			p = i;
			continue;	
		}
		else if(a[i] == 'E') break;
		else b[indexb++] = a[i]; 
	}
	i++;
	while(i < strlen(a)) s += a[i++];
	index = stoi(s);
	if(a[0] == '-') printf("-");
	if(p - 1 + index <= 0) {
		printf("0.");
		for(i = p - 1 + index; i < 0; i++)
			printf("0");
		printf("%s", b);
	} else {
		indexb = 0;
		for(i = 0; indexb < strlen(b) || i < p-1+index; i++)
		{
			if(indexb >= strlen(b)) printf("0");
			else {
				if(i == p-1+index) printf(".");
				else printf("%c", b[indexb++]);
			}
		}
	}
	return 0;
}
