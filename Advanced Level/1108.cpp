#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int n, i, j, cnt = 0;
	char s[50], t[50];
	double ans = 0.0, temp;
	cin >> n;
	for(i = 0; i < n; i++)
	{
		bool flag = true;
		scanf("%s", s);
		sscanf(s, "%lf", &temp);
		sprintf(t, "%.2lf", temp);
		for(j = 0; j < strlen(s); j++)
			if(s[j] != t[j]) {
				flag = false;
				break;
			}
		if(flag == false || temp > 1000 || temp < -1000) printf("ERROR: %s is not a legal number\n", s);
		else {
			cnt++;
			ans += temp;
		}
	}
	if(cnt == 0) printf("The average of 0 numbers is Undefined");
	else if(cnt == 1) printf("The average of 1 number is %.2lf", ans);
	else printf("The average of %d numbers is %.2lf", cnt, ans/cnt);
	return 0;
}
