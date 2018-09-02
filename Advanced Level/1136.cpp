#include <iostream>
#include <vector>
using namespace std;
vector<int> strToVec(string s)
{
	vector<int> v;
	for(int i = 0; i < s.length(); i++)
		v.push_back(s[i]-'0');
	return v;
}
vector<int> inverse(vector<int> q)
{
	vector<int> p;
	for(int i = q.size()-1; i >= 0; i--)
		p.push_back(q[i]);
	return p;
}
vector<int> pushZero(vector<int> q, int l)
{
	int index = 0;
	while(index < l) {
		if(index >= q.size()) q.push_back(0);
		index++;
	}
	return q;
}
vector<int> add(vector<int> q, vector<int> p)
{
	vector<int> ans;
	int l = max(q.size(), p.size());
	q = pushZero(q, l);
	p = pushZero(p, l);
	vector<int> rq = inverse(q);
	vector<int> rp = inverse(p);
	int carry = 0;
	for(int i = 0; i < l; i++)
	{
		ans.push_back((rq[i] + rp[i] + carry) % 10);
		carry = (rq[i] + rp[i] + carry) / 10;
	}
	if(carry != 0) ans.push_back(carry);
	return inverse(ans);
}
bool isPalindromic(vector<int> q)
{
	for(int i = 0; i < q.size() / 2; i++)
		if(q[i] != q[q.size()-1-i]) return false;
	return true;
}
void printv(vector<int> q)
{
	for(int i = 0; i < q.size(); i++)
		cout << q[i];
}
int main()
{
	vector<int> q, p;
	string s;
	cin >> s;
	q = strToVec(s);
	int iter = 0;
	while(!isPalindromic(q) && iter < 10)
	{
		p = inverse(q);
		printv(q);
		cout << " + ";
		printv(p);
		cout << " = ";
		q = add(q, p);
		printv(q);
		cout << endl;
		iter++;
	}
	if(isPalindromic(q)) {
		printv(q);
		cout << " is a palindromic number." << endl;
	} else cout << "Not found in 10 iterations." << endl;
	return 0;
}
