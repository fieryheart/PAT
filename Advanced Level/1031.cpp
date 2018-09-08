#include <iostream>
using namespace std;
int main()
{
	string s;
	int i, j, l, r, c, N;
	cin >> s;
	N = s.length();
	for(i = 1; i <= N+2-2*i && N+2-2*i >= 3 && N+2-2*i <= N; i++);
	l = r = i-1;
	c = N - r*2 + 2;
	char u[80][80];
	for(i = 0; i < l; i++)
	{
		for(j = 0; j < c; j++)
		{
			if(i == l-1) u[i][j] = s[i+j];
			else {
				if(j == 0) u[i][j] = s[i];
				else if(j == c-1) u[i][j] = s[N-1-i];
				else u[i][j] = ' ';
			}
		}
	}
	for(i = 0; i < l; i++)
	{
		for(j = 0; j < c; j++)
			printf("%c", u[i][j]);
		printf("\n");
	}
	return 0;
}
