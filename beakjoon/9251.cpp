#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int ct[1001][1001] = { 0 };

int main()
{
	string a, b;
	cin >> a >> b;

	int al = a.size(), bl = b.size();

	for (int i = 0; i<al; ++i)
		for (int j = 0; j<bl; ++j)
			if (a[i] == b[j])
				ct[i + 1][j + 1] = ct[i][j] + 1;
			else
				ct[i + 1][j + 1] = max(ct[i][j + 1], ct[i + 1][j]);

	printf("%d", ct[al][bl]);
}
