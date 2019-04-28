#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

const string FAIL = "IMPOSSIBLE";
char D[11];
string str;
int N, M;

int append(int cur, int edgeNum, int mod)
{
	int next = cur * 10 + edgeNum;
	if (next >= mod) return mod + next % mod;
	return next % mod;
}

void solve()
{
	vector<int> parent(2 * N, -1);
	vector<char> edge(2 * N);
	queue<int> qu;
	string path;

	parent[0] = 0;
	qu.push(0);

	while (!qu.empty()) {
		int cur = qu.front();
		qu.pop();
		for (int i = 0; i < str.size(); ++i) {
			int next = append(cur, str[i] - '0', N);
			if (parent[next] == -1) {
				parent[next] = cur;
				edge[next] = str[i];
				qu.push(next);
			}
		}
	}
	if (parent[N + M] == -1) {
		cout << FAIL << endl;
		return;
	}

	int trace = N + M;
	while (parent[trace] != trace) {
		path += char(edge[trace]);
		trace = parent[trace];
	}
	reverse(path.begin(), path.end());
	cout << path << endl;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%s %d %d", D, &N, &M);
		str = D;
		sort(str.begin(), str.end());
		solve();
	}
}
