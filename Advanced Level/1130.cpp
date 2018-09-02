#include <iostream>
using namespace std;
struct Node {
	string val;
	int left, right;
	bool isRoot = true;
}tree[30];
int root;
string preorder(int index)
{
	if(index == -1) return "";
	string s = tree[index].val;
	if(tree[index].right != -1) {
		s = preorder(tree[index].left) + s + preorder(tree[index].right);
		if(index != root) s = "(" + s + ")";	
	}
	return s;
}
int main()
{
	int n, i;
	cin >> n;
	for(i = 1; i <= n; i++)
	{
		cin >> tree[i].val >> tree[i].left >> tree[i].right;
		tree[tree[i].left].isRoot = tree[tree[i].right].isRoot = false;
	}
	for(i = 1; i <= n; i++)
		if(tree[i].isRoot == true)
			root = i;
	string str = preorder(root);
	cout << str;
	return 0;
}
