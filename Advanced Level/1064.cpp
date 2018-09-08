#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
vector<int> pre, level;
int tree[1010][3], index = 0;
int getheight(int nnum)
{
	if(nnum == 0) return 0;
	int h = 1;
	while(true) {
		if(nnum >= pow(2, h-1) && nnum <= pow(2, h)-1) return h;
		h++;
	}
}
int createCBST(int left, int right)
{
	if(left > right) return -1;
	int root = index;
	index++;
	if(left == right) {
		tree[root][0] = pre[left];
		tree[root][1] = -1;
		tree[root][2] = -1;
		return root;
	}
	if(right > left) {
		int nnum = right - left + 1, lnum, rnum;
		int h = getheight(nnum);
		int cnum = pow(2, h-1) -1 + pow(2, h-1)/2;
		if(nnum > cnum) {
			lnum = pow(2, h-1) - 1;
		} else {
			rnum = pow(2, h-2) - 1;
			lnum = nnum - rnum - 1;
		}
		int ln = createCBST(left, left+lnum-1);
		int rn = createCBST(left+lnum+1, right);
		tree[root][0] = pre[left+lnum];
		tree[root][1] = ln;
		tree[root][2] = rn;
		return root;
	}
	
}
int main()
{
	int n,i, root;
	cin >> n;
	pre.resize(n);
	for(i = 0; i < n; i++)
		scanf("%d", &pre[i]);
	sort(pre.begin(), pre.end());
	root = createCBST(0, n-1);
	queue<int> q;
	q.push(root);
	while(!q.empty()) {
		int v = q.front();
		level.push_back(tree[v][0]);
		q.pop();
		if(tree[v][1] != -1) q.push(tree[v][1]);
		if(tree[v][2] != -1) q.push(tree[v][2]);
	}
	for(i = 0; i < level.size(); i++)
	{
		if(i != 0) printf(" ");
		printf("%d", level[i]);
	}
	return 0;
}
