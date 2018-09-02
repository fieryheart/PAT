#include <iostream>
#include <vector>
using namespace std;
vector<int> in, pre, post;
int n;
int flag = 1;
void inorder(int preLeft, int preRight, int postLeft, int postRight)
{
	if(preRight == preLeft) {
		in.push_back(pre[preLeft]);
		return;
	}
	if(pre[preLeft] == post[postRight]) {
		int index = preLeft+1;
		while(index < preRight && pre[index] != post[postRight-1]) index++;
		if(index - preLeft > 1) inorder(preLeft+1, index-1, postLeft, postLeft+(index-preLeft-1)-1);
		else flag = 0;
		in.push_back(pre[preLeft]);
		inorder(index, preRight, postLeft+(index-preLeft-1), postRight-1);
	}
}
int main()
{
	int i;
	cin >> n;
	pre.resize(n);
	post.resize(n);
	for(i = 0;i < n; i++)
		scanf("%d", &pre[i]);
	for(i = 0;i < n; i++)
		scanf("%d", &post[i]);
	inorder(0, n-1, 0, n-1);
	if(flag == 1) cout << "Yes" << endl;
	else cout << "No" << endl;
	for(i = 0; i < in.size(); i++)
	{
		if(i!=0) cout << " ";
		cout << in[i];
	}
	cout << endl;
	return 0;
}
