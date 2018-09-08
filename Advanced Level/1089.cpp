#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> seq1, seq2;
int index = 0;
bool judge1()
{
	int i;
	for(i = 1; i < seq2.size(); i++)
		if(seq2[i] < seq2[i-1]) break;
	index = i;
	for(; i < seq1.size(); i++)
		if(seq1[i] != seq2[i]) return false;
	return true;
}
int main()
{
	int n, i;
	cin >> n;
	seq1.resize(n);
	seq2.resize(n);
	for(i = 0; i < n; i++)
		scanf("%d", &seq1[i]);
	for(i = 0; i < n; i++)
		scanf("%d", &seq2[i]);
	if(judge1()) {
		sort(seq2.begin(), seq2.begin()+index+1);
		printf("Insertion Sort\n");
		for(i = 0; i < seq2.size(); i++)
		{
			if(i != 0) printf(" ");
			printf("%d", seq2[i]);
		}
	} else {
		int flag = 1, k = 1;
		while(flag) {
			flag = 0;
			for(i = 0; i < seq2.size(); i++)
				if(seq1[i] != seq2[i]) {
					flag = 1;
					break;
				}
			k *= 2;
			for(i = 0; i+k < seq1.size(); i+=k)
				sort(seq1.begin()+i, seq1.begin()+i+k);
			sort(seq1.begin()+i, seq1.end());
		}
		printf("Merge Sort\n");
		for(i = 0; i < seq1.size(); i++)
		{
			if(i != 0) printf(" ");
			printf("%d", seq1[i]);
		}
	}
	return 0;
}
