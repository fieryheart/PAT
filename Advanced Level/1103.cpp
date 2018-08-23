#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> unit, tempPath;
vector< vector<int> > path;
int n,k,p, maxsum = -1;
void printv(vector<int> v)
{
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl; 
}
void dfs(int index, int num, int sum, int numSum)
{
	if(num > k) return ;
	if(num == k && sum == n) {
		if(numSum + index > maxsum) {
			maxsum = numSum + index;
			path.clear();
			path.push_back(tempPath); 
		} else if(numSum + index == maxsum) {
			path.push_back(tempPath);
		}
		return ;
	}
	for(int i = index; i >= 1; i--)
		if(sum + unit[i] <= n) {
			tempPath.push_back(i);
			dfs(i, num + 1, sum + unit[i], numSum + index);
			tempPath.pop_back();
		}
}
int main()
{
	int i,index = 1,temp = 1;
	cin >> n >> k >> p;
	while(temp <= n) {
		unit.push_back(temp);
		temp = pow(index, p);
		index++;
	}
	dfs(unit.size()-1, 0, 0, 0);
	if(path.size() == 0) {
		cout << "Impossible" << endl;
		return 0;
	}
	cout << n << " = ";
	for(i = 0; i < path[0].size(); i++)
	{
		if(i != 0) printf(" + ");	
		printf("%d^%d", path[0][i], p);
	}
	return 0;
}
