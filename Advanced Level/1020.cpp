#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int tree[40][2];
vector<int> in,post,level;
int getLevel(int inL, int inR, int postL, int postR)
{
	if(inL == inR) {
		tree[in[inL]][0] = -1;
		tree[in[inL]][1] = -1;
		return in[inL];
	}
	if(inR > inL)
	{
		int index = inL;
		while(index <= inR && in[index] != post[postR]) index++;
		int left = getLevel(inL, index-1, postL, postL+(index-inL)-1);
		int right = getLevel(index+1, inR, postL+(index-inL), postR-1);
		tree[in[index]][0] = left;
		tree[in[index]][1] = right;
		return in[index]; 
	}
	return -1;
}
int main()
{
	int n,i, root;
	cin >> n;
	in.resize(n);
	post.resize(n);
	for(i = 0; i < n; i++)
		scanf("%d", &post[i]);
	for(i = 0; i < n; i++)
		scanf("%d", &in[i]);
	root = getLevel(0,n-1,0,n-1);
	queue<int> q;
	q.push(root);
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		level.push_back(v);
		if(tree[v][0] != -1) q.push(tree[v][0]);
		if(tree[v][1] != -1) q.push(tree[v][1]);
	}
	for(i = 0; i < level.size(); i++)
	{
		if(i!=0)printf(" ");
		printf("%d", level[i]);
	}
	return 0;
}
