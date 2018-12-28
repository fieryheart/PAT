/*
	Given an array of integers, return indices of the two numbers such that they add up to a specific target.
	
	You may assume that each input would have exactly one solution, and you may not use the same element twice.
	
	Example:
	
	Given nums = [2, 7, 11, 15], target = 9,
	
	Because nums[0] + nums[1] = 2 + 7 = 9,
	return [0, 1].
 
	
	map映射 
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
    int i;
    vector<int> rst;
    rst.resize(2, 0);
    map<int, vector<int>> mapp;
    for(i = 0; i < nums.size(); i++)
    	mapp[nums[i]].push_back(i);
    for(i = 0; i < nums.size(); i++)
    {
    	int num1 = target - nums[i];
        // 负数情况
        if(mapp[num1].size() > 0)
        {
        	// 找到就退出 
        	if(num1 == nums[i]){
				if(mapp[num1].size() > 1) {
					rst[0] = mapp[num1][0];
        			rst[1] = mapp[num1][1];	
        			break;
				} else continue;
			} else {
	            rst[0] = i;
	            rst[1] = mapp[target - nums[i]][0];
	            break;
			}
        }
    }
    // 没有结果情况
    return rst;
}
int main()
{
	vector<int> nums = {3,2,4};
	int target = 6;
	vector<int> rst = twoSum(nums, target);
	cout << rst[0] << " " << rst[1] << endl;
	return 0;
 } 
