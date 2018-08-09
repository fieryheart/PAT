#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int i, next[2020]={0};
	string s, s1;
	getline(cin, s);
	s1 = "#";
	for(i = 0; i < s.length(); i++)
	{
		s1 += s[i];
		s1 += "#";	
	}
	next[0] = 0;
	next[1] = 1;
	for(i = 2; i < s1.length(); i++)
	{
		if(next[i-2] < next[i-1]-2) {
			next[i] = next[i-2];
		} else {
			int j = next[i-1]-1;
//			int j = 0;
			while(i+j < s1.length() && i-j >= 0 && s1[i+j] == s1[i-j])
				j++;
			next[i] = j-1;
		}
	}
	int maxn = -1;
	for(i = 0; i < s1.length(); i++)
		if(next[i] > maxn) maxn = next[i];
	cout << maxn;
	return 0;
}
