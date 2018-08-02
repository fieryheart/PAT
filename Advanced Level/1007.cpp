#include <iostream>
#include <vector>
using namespace std;
vector<int> seq;
int main()
{
	int k, fir, last,temp, ThisSum = 0, maxSum = -1;
	cin >> k;
	seq.resize(k);
	fir = 0;
	last = k - 1;
	for(int i = 0; i < k; i++)
	{
		scanf("%d", &seq[i]);
		ThisSum += seq[i];
		if(ThisSum < 0) {
			ThisSum = 0;
			temp = i+1;
		} else if(ThisSum > maxSum) {
			maxSum = ThisSum;
			fir = temp;
			last = i;
		}
	}
	if(maxSum < 0) maxSum = 0;
	cout << maxSum << " " << seq[fir] << " " << seq[last];
	return 0; 
} 
