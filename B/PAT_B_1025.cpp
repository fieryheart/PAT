#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{

	int nums[100000][2];

	string s;
	cin >> s;
	int start = stoi(s);

	int num, unit, i;

	cin >> num >> unit;

	string address, data, next;
	for(i = 0; i < num; i++) {
		cin >> address >> data >> next;
		int ad = stoi(address), da = stoi(data), ne = stoi(next);
		nums[ad][0] = da;
		nums[ad][1] = ne;
	}


	int remind = num % unit;
	int pos = 0;
	int next_group_start = start;
	if(remind == 0) {
		next_group_start = -1; 
	}else{
		while(pos != num - remind) {
			next_group_start = nums[next_group_start][1];
			pos++;
		}

		cout << next_group_start << endl;
	}

	int point = start;
	int arr[unit][2];

	while(pos > 0) {

		

	}




	while(point != -1) {
		if(nums[point][1] != -1)
			printf("%05d %d %05d\n", point, nums[point][0], nums[point][1]);
		else
			printf("%05d %d %d\n", point, nums[point][0], nums[point][1]);
		point = nums[point][1];
	}

	return 0;
}