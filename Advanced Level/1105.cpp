#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int matrix[110][110];
bool cmp(int q, int p)
{
	return q > p;
}
int main()
{
	int n, i;
	cin >> n;
	v.resize(n);
	for(i = 0; i < n; i++)
		scanf("%d", &v[i]);
	sort(v.begin(), v.end(), cmp);
	int minn = 99999999, row, col;
	for(i = 1; i*i <= n; i++)
		if(n % i == 0 && abs(i - n/i) < minn) {
			minn = abs(i - n/i);
			row = max(i, n/i);
			col = min(i, n/i);
		}
	fill(matrix[0], matrix[0]+110*110, -1);
	int posX = 1, posY = 1, index = 0, dire = 1;
	while(index < n) {
		matrix[posX][posY] = v[index++];
		if(dire == 1){
			if(posY < col && matrix[posX][posY+1] == -1) {
				posY++;
			}else{
				posX++;
				dire = 2; 
			}
		} else if(dire == 2) {
			if(posX < row && matrix[posX+1][posY] == -1) {
				posX++;
			} else {
				posY--;
				dire = 3;
			}
		} else if(dire == 3) {
			if(posY > 1 && matrix[posX][posY-1] == -1) {
				posY--;
			} else {
				posX--;
				dire = 4;
			}
		} else if(dire == 4) {
			if(posX > 1 && matrix[posX-1][posY] == -1) {
				posX--;
			}else {
				posY++;
				dire = 1;
			}
		}
	}
	for(int i = 1; i <= row; i++) {
		for(int j = 1; j <= col; j++)
		{
			if( j != 1) printf(" ");
			printf("%d", matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}
