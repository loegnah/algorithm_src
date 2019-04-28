#include <iostream>
#include <map>
using namespace std;

int N;
map<int, int> tree;

void removePeople(int p, int q)
{
	map<int, int>::iterator iter = tree.lower_bound(p);
	map<int, int>::iterator tmp;

	if (iter == tree.begin()) return;
	
	--iter;
	while (true) {
		if (iter->second > q) break;
		
		if (iter == tree.begin()) {
			tree.erase(iter);
			continue;
		}
		tmp = iter;
		--iter;
		tree.erase(tmp);
	}
}

bool isQualified(int p, int q)
{
	map<int, int>::iterator iter = tree.lower_bound(p);
	
	if (iter == tree.end()) return true;

	return q > iter->second;
}

int solve()
{
	int ans = 0;
	int p, q;
	
	tree.clear();
	for (int i = 0; i < N; ++i) {
		scanf("%d %d", &p, &q);
		
		if (!isQualified(p, q)) {
			ans += tree.size();
			continue;
		}
		removePeople(p, q);
		tree[p] = q;
		ans += tree.size();
	}
	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);
	
	while (T--) {
		scanf("%d", &N);
		printf("%d\n",solve());
	}
}