#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int visit[1010] = {0};
int main()
{
	int m, n, k, i, j, t, num;
	cin >> m >> n >> k;
	for(i = 0; i < k; i++)
	{
		bool flag = true;
		stack<int> st;
		fill(visit, visit+1010, 0);
		for(j = 0; j < n; j++)
		{
			scanf("%d", &num);
			if(flag) { 				
				if(!st.empty() && num < st.top()) {
					flag = false;
				} else {
					for(t = 1; t <= num; t++)
						if(visit[t] == 0) {
							st.push(t);
							visit[t] = 1;	
						}
					if(st.size() > m) flag = false;
					st.pop();
				}
			}
		}
		if(flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;	
}


//#include <iostream>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int m, n, c, last = 0, This, capacity = 0, max;
//	int num[1010] = {0};
//	cin >> m >> n >> c;
//	for(int i = 0; i < c; i++)
//	{
//		int flag = 0;
//		max = 0;
//		capacity = 0;
//		fill(num, num+1010, 0);
//		for(int j = 0; j < n; j++) {
//			
//			scanf("%d", &This);
//			num[This] = 1;
//			if(flag == 1) continue;
//
//			if(This > max) {
//				max = This;
//			} else {
//				for(int k = This; k < max; k++)
//					if(num[k] != 1) flag = 1;
//			}
//			if(max - capacity > m) flag = 1;		
//			capacity++;
//		}
//		if(flag == 0) cout << "YES" << endl;
//		else cout << "NO" << endl;
//	}
//	return 0;
//}
