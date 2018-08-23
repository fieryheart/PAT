#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int n, i, j, cnt = 0;
	char s[50], t[50];
	double temp, sum = 0.0;
	cin >> n;
	for(i = 0; i < n; i++)
	{
		int flag = 0;
		scanf("%s", s);
		sscanf(s, "%lf", &temp);
		sprintf(t, "%.2lf", temp);
		for(j = 0; j < strlen(s); j++)
			if(s[j] != t[j]) {
				flag = 1;
				break;
			}
		if(flag == 1 || temp > 1000 || temp < -1000) {
			printf("ERROR: %s is not a legal number\n", s);
		} else {
			cnt++;
			sum += temp;
		}
	}
	if(cnt == 0) printf("The average of 0 numbers is Undefined");
	else if(cnt == 1) printf("The average of 1 number is %.2lf", sum);
	else printf("The average of %d numbers is %.2lf", cnt, sum/cnt);
	return 0;
}
