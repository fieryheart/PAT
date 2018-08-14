#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int v[1010];
int tree[2010][2];
int getH(int num)
{
	int i = 0;
	for(; num > pow(2, i+1)-1; i++);
	return i;
}
int createT(int left, int right)
{
	int nnum = right-left+1;
//	cout << "nnum: " << nnum << " ";
	if(nnum == 1) {
//		cout << "root: " << v[left] << endl;
		tree[v[left]][0] = -1;
		tree[v[left]][1] = -1;
		return v[left];
	} else if(nnum > 1){
		int h = getH(nnum), ln;
		int lt = pow(2, h) - 1;
		int rrest = nnum - lt;
		if(rrest <= pow(2, h-1))
			ln = pow(2, h-1) - 1 + rrest;
		else
			ln = pow(2, h) - 1;
		
//		cout << "root: " << v[left+ln] << " " << "h: " << h << endl; 
		int leftT=-1, rightT=-1;
		if(left+ln-1 >= left)		
			leftT = createT(left, left+ln-1);
		if(right >= left+ln+1)
			rightT = createT(left+ln+1, right);
		tree[v[left+ln]][0] = leftT;
		tree[v[left+ln]][1] = rightT;
		return v[left+ln];
	}
}
int main()
{
	int n, i;
	cin >> n;
	for(i = 0; i < n; i++)
		scanf("%d", &v[i]);
	sort(v,v+n);
	int root = createT(0, n-1);
	queue<int> q;
	vector<int> level;
	q.push(root);
	while(!q.empty())
	{
		int w = q.front();
		q.pop();
		level.push_back(w);
		if(tree[w][0] != -1) q.push(tree[w][0]);
		if(tree[w][1] != -1) q.push(tree[w][1]);
//		cout << w << " " << tree[w][0] << " " << tree[w][1] << endl;
	}
	for(i = 0; i < level.size(); i++)
	{
		if(i != 0) printf(" ");
		printf("%d", level[i]);
	}
	return 0;
}
