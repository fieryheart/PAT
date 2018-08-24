#include <iostream>
#include <algorithm>
using namespace std;
int tree[1010][3];
int tDepth = 0, n1=0, n2=0;
void insert(int root, int val, int node)
{
	if(val <= tree[root][0] && tree[root][1] == -1){
		tree[root][1] = node;
	} else if(val <= tree[root][0] && tree[root][1] != -1){
		insert(tree[root][1], val, node);
	} else if(val > tree[root][0] && tree[root][2] == -1){
		tree[root][2] = node;
	} else if(val > tree[root][0] && tree[root][2] != -1){
		insert(tree[root][2], val, node);
	}
}
void getDepth(int root, int depth)
{
	if(tree[root][1] == -1 && tree[root][2] == -1) {
		if(depth > tDepth){
			tDepth = depth;
		}
		return;
	}
	if(tree[root][1] != -1) getDepth(tree[root][1], depth+1);
	if(tree[root][2] != -1) getDepth(tree[root][2], depth+1);
}
void getLevel(int root, int depth)
{
	if(depth == tDepth) n1++;
	if(depth == tDepth-1) n2++;
	if(tree[root][1] == -1 && tree[root][2] == -1) {
		return;
	}
	if(tree[root][1] != -1) getLevel(tree[root][1], depth+1);
	if(tree[root][2] != -1) getLevel(tree[root][2], depth+1);	
}
int main()
{
	fill(tree[0], tree[0]+1010*3, -1);
	int n, node, val;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &val);
		tree[i][0] = val;
		if(i != 0) insert(0, val, i);
	}
	getDepth(0, 1);
	getLevel(0, 1);
	cout << n1 << " + " << n2 << " = " << n1+n2 << endl;
	return 0;
}
