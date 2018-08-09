#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int p, int q)
{
	return p > q;
}
int main()
{
	int n,i,value;
	cin >> n;
	vector<int> ncoupon, pcoupon, nproduct, pproduct;
	for(i = 0; i < n; i++){
		scanf("%d", &value);
		if(value >= 0) pcoupon.push_back(value);
		else ncoupon.push_back(value);	
	}
	sort(pcoupon.begin(), pcoupon.end(), cmp);
	sort(ncoupon.begin(), ncoupon.end());
	cin >> n;
	for(i = 0; i < n; i++){
		scanf("%d", &value);
		if(value >= 0) pproduct.push_back(value);
		else nproduct.push_back(value);	
	}
	sort(pproduct.begin(), pproduct.end(), cmp);
	sort(nproduct.begin(), nproduct.end());
	int money = 0;
	for(i = 0; i < pcoupon.size() && i < pproduct.size(); i++)
			money += (pproduct[i] * pcoupon[i]);
	for(i = 0; i < ncoupon.size() && i < nproduct.size(); i++)
			money += (ncoupon[i] * nproduct[i]);
	cout << money;
	return 0;
}
