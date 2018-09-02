#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int main()
{
	int n, i, num, index = 1;
	cin >> n;
	for(i = 0; i < n; i++)
	{
		scanf("%d", &num);
		if(num > 0) v.push_back(num);
	}
	sort(v.begin(), v.end());
	for(i = 0; i < v.size(); i++)
		if(v[i] == index) index++;
		else if(v[i] < index) continue;
		else break;
	cout << index; 
	return 0;	
}
