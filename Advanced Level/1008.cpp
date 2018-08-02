#include <iostream>
using namespace std;
int main()
{
	int n, time=0,last=0,next;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		time += 5;
		scanf("%d", &next);
		time += (next-last) > 0 ? 6*(next-last) : 4*(last-next);
		last = next;
	}
	cout << time << endl;
	return 0;
}
