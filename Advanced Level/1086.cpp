#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> v, pre, in;
void postOrder(int start, int end, int origin)
{
	
	int index = -1;
	for(int i = start; i <= end; i++)
	{
		if(in[i] == pre[origin]){
			index = i;
			break;
		}
	}
	if(index == -1) return;
	postOrder(start, index-1, origin+1);
	postOrder(index+1, end, origin+1+(index-start));
	v.push_back(in[index]);
}
int main()
{
	stack<int> st;
	int n, num, root,input = 0;
	char cmd[10];
	cin >> n;
	while(input < n || !st.empty()) {
		scanf("%s", cmd);
		
		if(cmd[1] == 'u'){
			scanf("%d", &num);
			st.push(num);
			pre.push_back(num);
			input++;
		} else if(cmd[1] == 'o') {
			int top = st.top();
			in.push_back(top);
			st.pop();
 		}
	}
	postOrder(0, n-1, 0);
	for(int i = 0; i < v.size(); i++){
		if(i != 0) printf(" ");
		printf("%d",v[i]);	
	}
	return 0;
}
