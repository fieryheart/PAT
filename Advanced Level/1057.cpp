#include <iostream>
#include <stack>
using namespace std;
#define lowbit(i) ((i) & (-i))
stack<int> st;
int c[100010] = {0};
const int maxn = 100010;
void update(int n, int v)
{
	for(int i = n; i < maxn; i += lowbit(i))
		c[i] += v;
}
int getsum(int n)
{
	int sum = 0;
	for(int i = n; i >= 1; i -= lowbit(i))
		sum += c[i];
	return sum;
}
void peekmedian()
{
	int left = 0, right = maxn, k = (st.size()+1)/2;
	while(left < right)
	{
		int mid = (left+right)/2;
		if(getsum(mid) >= k)
			right = mid;
		else
			left = mid+1;
	}
	printf("%d\n", left);
}
int main()
{
	int n, i, num;
	char cmd[15];
	cin >> n;
	for(i = 0; i < n; i++)
	{
		scanf("%s", cmd);
		if(cmd[1] == 'o')
		{
			if(st.size() == 0) printf("Invalid\n");
			else {
				num = st.top();
				st.pop();
				update(num, -1);
				printf("%d\n", num);
			}
		} else if(cmd[1] == 'e') {
			if(st.size() == 0) printf("Invalid\n");
			else peekmedian();
		} else {
			scanf("%d", &num);
			st.push(num);
			update(num, 1);
		}
	}
	return 0;
}
