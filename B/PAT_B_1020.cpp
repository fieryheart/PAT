#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


struct product{
	int num;
	float price;
};

bool cmp(struct product p,struct product q) {
	return p.price > q.price;
}

int main()
{

	int type, limit;
	float real = 0.0;
	cin >> type >> limit;

	int i;
	float amount[type], money[type];
	struct product p[type];


	for (i = 0; i < type; i++)
		cin >> amount[i];
	for (i = 0; i < type; i++)
		cin >> money[i];
	for (i = 0; i < type; i++) {
		p[i].num = i;
		p[i].price = money[i] / amount[i];
	}

	// sort(price, price+type, cmp);
	
	sort(p, p+type, cmp);

	// int pos = 0;
	float rst = 0.0;

	// for (i = 0 ; i < type; i++)
	// 	cout << p[i].num << " : " << p[i].price << endl;

	// while(real < limit && pos < type) {
	for (i = 0; i < type; i++){

		int index = p[i].num;

		real += amount[index];

		if(real <= limit) {

			rst += money[index]*1.0;

		} else {
			rst += p[i].price* 1.0 * (limit + amount[index] - real);
			
			// rst += p[i].price * limit;
			break;
		}

		// limit -= amount[index];

	}
		// pos++;
	// }

	printf("%.2f", rst);

	return 0;
}