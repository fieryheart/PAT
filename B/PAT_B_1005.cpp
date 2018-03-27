#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool myFunction(int i, int j) 
{
	return i > j;
}

int main()
{
	int i,c,n,pos = 0;
	std::vector<int> v;
	cin >> c;

	for(i = 0; i < c; i++)
	{
		cin >> n;
		v.push_back(n);
	}

	while(pos <= v.size())
	{
		int num = v[pos];
		while (num != 1){

			if ( num % 2 ) { // odd

				num = (3*num + 1) / 2;

			} else { // even

				num = num / 2;

			}

			int result = v.size();
			
			for(i = 0; i < v.size(); i++)
			{
				if(num == v[i])
				{
					result = i;
					break;
				}

			}
			if (result != v.size())
			{
				if (result < pos) 
					pos--;
				v.erase(v.begin() + result);
			}
		}
		pos++;
	}

	// sort -> <algorithm>
	sort(v.begin(), v.end(), myFunction);	
	for(i = 0; i < v.size(); i++)
		if (i != v.size()-1)
			cout << v[i] << ' ';
		else
			cout << v[i];


	return 0;
}
