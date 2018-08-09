#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;
int main()
{
	int n,i, fmax = -1, mmin = 101;
	char fname[15], fid[15], mname[15], mid[15];
	cin >> n;
	for(i = 0; i < n; i++)
	{
		char gender, name[15], id[15];
		int grade;
		scanf("%s %c %s %d", name, &gender, id, &grade);
		if(gender == 'M' && grade < mmin) {
			mmin = grade;
			strcpy(mname,name);
			strcpy(mid,id);
		}
		if(gender == 'F' && grade > fmax) {
			fmax = grade;
			strcpy(fname, name);
			strcpy(fid,id);
		}
	}
	if(fmax == -1) printf("Absent\n");
	else printf("%s %s\n", fname, fid);
	if(mmin == 101) printf("Absent\n");
	else printf("%s %s\n", mname, mid);
	if(fmax == -1 || mmin == 101) printf("NA\n");
	else printf("%d\n", abs(fmax-mmin));
	return 0;
}
