#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
void toNum(int num, int radix)
{
	while(num != 0)
	{
		v.push_back(num%radix);
		num /= radix;
	}
}
bool isPalin()
{
	for(int i = 0; i < v.size() / 2; i++)
		if(v[i] != v[v.size()-1-i]) return false;
	return true;
}
int main()
{
	int n, radix;
	cin >> n >> radix;
	toNum(n, radix);
	if(n == 0) {
		printf("Yes\n0");
		return 0;
	}
	if(isPalin()) printf("Yes\n");
	else printf("No\n");
	for(int i = v.size()-1; i >= 0; i--)
	{
		cout << v[i];
		if(i != 0) printf(" ");	
	}
	return 0;
}
