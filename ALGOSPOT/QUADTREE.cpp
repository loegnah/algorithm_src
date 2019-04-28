#include <iostream>
#include <string>
using namespace std;

string QuadTree(string::iterator& it)
{
	char ch = *it;
	++it;

	if (ch == 'b' || ch == 'w') return string(1, ch);
	
	string imsi1 = QuadTree(it);
	string imsi2 = QuadTree(it);
	string imsi3 = QuadTree(it);
	string imsi4 = QuadTree(it);
	string ret = "x" + imsi3 + imsi4 + imsi1 + imsi2;
	return ret;
}
int main()
{
	int C;
	int strSize = 0;
	string baseStr;
	string::iterator str_iter;
	
	baseStr.reserve(1000);
	
	cin >> C;
	while (C-- > 0) {
		cin >> baseStr;
		str_iter = baseStr.begin();
		cout << QuadTree(str_iter) << endl;
	}
}