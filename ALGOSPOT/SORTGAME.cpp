#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> arr;
map<vector<int>, int> toSorted;

vector<int> simplify(vector<int>& input) {
	vector<int> ret;
	for (int i = 0; i < N; ++i) {
		int a = 0;
		for (int j = 0; j < N; ++j)
			if (input[i] > input[j])
				++a;
		ret.push_back(a);
	}
	return ret;
}

void solve()
{
	vector<int> input;
	int tmp;

	for (int i = 0; i < N; ++i) {
		scanf("%d", &tmp);
		input.push_back(tmp);
	}
	arr = simplify(input);
	printf("%d\n", toSorted[arr]);

}

void ini(int n)
{
	vector<int> parr(n);
	queue<vector<int> > q;
		
	for (int i = 0; i < n; ++i) parr[i] = i;
	toSorted[parr] = 0;
	q.push(parr);
	while (!q.empty()) {
		vector<int> here = q.front();
		q.pop();
		int cost = toSorted[here];
		for (int i = 0; i < n; ++i) {
			for (int j = i + 2; j <= n; ++j) {
				reverse(here.begin() + i, here.begin() + j);
				if (toSorted.count(here)== 0) {
					toSorted[here] = cost + 1;
					q.push(here);
				}
				reverse(here.begin() + i, here.begin() + j);					
			}
		}
	}
	
}

int main()
{
	int T;
	for (int n = 1; n <= 8; ++n)
		ini(n);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		solve();
	}
}
