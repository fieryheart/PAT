#include <iostream>
using namespace std;
int main()
{
	double val,sum=1;
	char odds[3] = {'W','T','L'};
	for(int i = 0; i < 3; i++)
	{
		double max = -1;
		int index = -1;
		for(int j = 0; j < 3; j++){
			scanf("%lf",&val);
			if(val > max) {
				max = val;
				index = j;	
			}
		}
		sum *= max;
		printf("%c ", odds[index]);
	}
	printf("%.2lf", (sum*0.65-1)*2);
	return 0;
}
