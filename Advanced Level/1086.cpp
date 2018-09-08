#include <iostream>
#include <vector>
#include <stack>
using namespace std;
stack<int> st;
vector<int> pre,in,post;
void getpost(int inLeft, int inRight, int preLeft, int preRight)
{
	if(inLeft == inRight) {
		post.push_back(in[inLeft]);
		return;
	} else if(inRight > inLeft) {
		int index = inLeft;
		while(index <= inRight && in[index] != pre[preLeft]) index++;
		getpost(inLeft, index-1, preLeft+1, preLeft+index-inLeft);
		getpost(index+1, inRight, preLeft+index-inLeft+1, preRight);
		post.push_back(in[index]);
	}
}
int main()
{
	int n, i, num;
	char cmd[10];
	cin >> n;
	for(i = 0; i < n*2; i++)
	{
		scanf("%s", cmd);
		if(cmd[1] == 'u') {
			scanf("%d", &num);
			st.push(num);
			pre.push_back(num);
		} else if(cmd[1] == 'o') {
			in.push_back(st.top());
			st.pop();
		}
	}
	getpost(0, n-1, 0, n-1);
	for(i = 0; i < post.size(); i++)
	{
		if(i != 0) printf(" ");
		printf("%d", post[i]);
	}
	return 0;
}
