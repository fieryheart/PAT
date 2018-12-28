#include <iostream>
using namespace std;
int lengthOfLongestSubstring(string s) {
    int mapp[128] = {0},  maxl = 0, start = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(mapp[s[i]] && mapp[s[i]] > start) {
            start = mapp[s[i]];
        }
        mapp[s[i]] = i+1;
        maxl = max(maxl, i+1-start);
    }
    return maxl;
}
int main()
{
	string s = " ";
	int rst = lengthOfLongestSubstring(s);
	cout << rst << endl;
	return 0;
}
