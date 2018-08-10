#include <iostream>
using namespace std;
int rule[55], cards[55][2];
void doShuff(int n)
{
	int t0 = 0, t1 = 1;
	if(n%2 == 1) {
		t0 = 1;
		t1 = 0;
	}
	for(int i = 1; i <= 54; i++)
		cards[rule[i]][t1] = cards[i][t0]; 
}
void printCard(int n)
{
	
	if(n >= 53 && n <= 54) printf("J%d", n-52);
	if(n >= 40 && n <= 52) printf("D%d", n-39);
	if(n >= 27 && n <= 39) printf("C%d", n-26);
	if(n >= 14 && n <= 26) printf("H%d", n-13);
	if(n >= 1 && n <= 13) printf("S%d", n-0);
	
}
int main()
{
	int n, i, t = 0, count;
	cin >> n;
	count = 0;
	for(i = 1; i <= 54; i++)
		cards[i][0] = i;
	for(i = 1; i <= 54; i++)
		scanf("%d", &rule[i]);
	while(n != 0){
		doShuff(count);
		count++;
		n--;
	}
	if(count%2 == 1) t = 1;
	for(i = 1; i <= 54; i++)
	{
		if(i != 1) printf(" ");
		printCard(cards[i][t]);
	}
	return 0;
}
