#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct Stu{
	string name;
	int height;
}stu;
vector<stu> v,ans;
bool cmp(stu q, stu p)
{
	return q.height != p.height ? q.height < p.height : q.name > p.name;
}
int main()
{
	int n, k, i, j, temp = -1;
	cin >> n >> k;
	k = n / k;
	v.resize(n);
	ans.resize(n);
	for(i = 0; i < n; i++)
		cin >> v[i].name >> v[i].height;
	sort(v.begin(), v.end(), cmp);
	for(i = 0; i < n; i += k) {
		if((n-i) / k < 2) temp = n - i;
		else temp = k;
		int center = i + temp/2, flag = 0, index=1;
		ans[center] = v[i+temp-1];
		for(j = i+temp-2; j >= i; j--)
		{
			if(flag == 0) {
				ans[center-index] = v[j];
				flag = 1;
			} else if(flag == 1) {
				ans[center+index] = v[j];
				flag = 0;
				index++;
			}
		}
		if(temp != k) break;
	}
	for(i = n-temp; i < n; i++)
	{
		if(i != n-temp) cout << " ";
		cout << ans[i].name;
	}
	cout << endl;
	int t = (n-temp)/k;
	for(i = 1; i <= t; i++)
	{
		for(j = 0; j < k; j++)
		{
			if(j != 0) cout << " ";
			cout << ans[n-temp-k*i+j].name;
		}
		cout << endl;
	}
	return 0;
}
