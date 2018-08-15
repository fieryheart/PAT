#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp1(int q, int p)
{
	return q < p;
}
bool cmp2(int q, int p)
{
	return q > p; 
}
int Sort1(int num)
{
	vector<int> v;
	while(num != 0)
	{
		v.push_back(num % 10);
		num /= 10;
	}
	sort(v.begin(), v.end(), cmp1);
	int n = 0;
	for(int i = 0; i < v.size(); i++)
	{
		n = n * 10 + v[i];
	}	
	return n;
}
int Sort2(int num)
{
	vector<int> v;
	while(num != 0)
	{
		v.push_back(num % 10);
		num /= 10;
	}
	if(v.size() < 4) {
		int count = 4-v.size();
		for(int i = 0; i < count; i++) {
			v.push_back(0); 	
		}
	}
	sort(v.begin(), v.end(), cmp2);
	int n = 0;
	for(int i = 0; i < v.size(); i++)
	{
		n = n * 10 + v[i];
	}	
	return n;
}
int main()
{
	int num, num1, num2, flag = 0;
	cin >> num;
	while(num != 6174 || flag == 0) {
		flag = 1;
		num1 = Sort1(num);
		num2 = Sort2(num);
		if(num1 == num2) {
			printf("%04d - %04d = 0000", num1, num2);
			break;	
		} else {
			num = num2 - num1;
			printf("%04d - %04d = %04d\n", num2, num1, num);	
		}	
	}
	return 0;
}
