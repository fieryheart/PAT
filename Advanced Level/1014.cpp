#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Windows{
	int endd;
	queue<int> q;
}windows[25];
struct Customer{
	int dur, endd;
}customer[1010];
int main()
{
	int n,m,k,q, i, j, proc;
	cin >> n >> m >> k >> q;
	for(i = 1; i <= k; i++)
		scanf("%d", &customer[i].dur);
	for(i = 1; i <= k && i <= n*m; i++) {
		int win = (i-1) % n;
		windows[win].q.push(i);
		customer[i].endd = windows[win].endd + customer[i].dur;
		windows[win].endd = customer[i].endd;
	}
	for(i = n*m+1; i <= k; i++) {
		int win, min = 9999999;
		for(j = 0; j < n; j++) {
			int first = windows[j].q.front();
			if(customer[first].endd < min) {
				min = customer[first].endd;
				win = j;
			}
		}
		windows[win].q.pop();
		windows[win].q.push(i);
		customer[i].endd = windows[win].endd + customer[i].dur;
		windows[win].endd = customer[i].endd;
	}
	int id;
	for(i = 0; i < q; i++){
		scanf("%d", &id);
		int start = customer[id].endd - customer[id].dur;
		if(start < 540){
			printf("%02d:%02d\n", customer[id].endd/60+8, customer[id].endd%60);
		} else {
			printf("Sorry\n");
		}
	}
	return 0;
}
