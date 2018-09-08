#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
	int m,n,k,i,j,num,w;
	cin >> m >> n >> k;
	for(i = 0; i < k; i++)
	{
		bool flag = true;
		int last = 0, maxn = -1;
		vector<int> v;
		map<int, bool> mapp;
		for(j = 0; j < n; j++)
		{
			scanf("%d", &num);
			if(num > maxn) maxn = num;
			if(maxn - v.size() > m) flag = false;
			for(w = num+1; w < maxn; w++)
				if(mapp[w] == false) flag = false;
			mapp[num] = true;
			v.push_back(num);
		}
		if(flag == false) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}
