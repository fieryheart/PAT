#include <iostream>
#include <vector>
using namespace std;
vector<int> pre, in, post;
void getpost(int preLeft, int preRight, int inLeft, int inRight)
{
	if(inRight == inLeft) {
		post.push_back(in[inLeft]);
		return ;
	}
	if(inRight > inLeft) {
		int index = inLeft;
		while(index <= inRight && in[index] != pre[preLeft]) index++;
		getpost(preLeft+1, preLeft+(index-inLeft), inLeft, index-1);
		getpost(preLeft+(index-inLeft)+1, preRight, index+1, inRight);
		post.push_back(in[index]);
	}
}
int main()
{
	int n, i;
	cin >> n;
	pre.resize(n);
	in.resize(n);
	for(i = 0; i < n; i++)
		scanf("%d", &pre[i]);
	for(i = 0; i < n; i++)
		scanf("%d", &in[i]);
	getpost(0, n-1, 0, n-1);
	cout << post[0];
	return 0;
}
