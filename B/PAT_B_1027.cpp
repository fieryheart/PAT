#include <iostream>
#include <math.h>
using namespace std;

int main()
{

	int n;
	char c;

	cin >> n >> c;

	int f = 1;

	while(2*f*f - 1 <= n)
		f++;

	f--;


	int i, j, block, ch;
	for(i = 1; i <= 2*f-1;i++) {

		ch =  2*abs(i - f) + 1;
		block = 2*f-1 - ch;

		for(j = 1; j <= block / 2 + ch; j++) {

			if(j <= block / 2)
				printf(" ");
			else
				printf("%c", c);

		}
		printf("\n");
	}

	printf("%d", n-2*f*f+1);

	return 0;
}