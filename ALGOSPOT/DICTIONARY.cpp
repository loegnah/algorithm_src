#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int NUM = 26;

vector<vector<int> > graph;
vector<bool> isVisited;
vector<int> ans;
vector<int> aaa;

void dfs(int here)
{
	isVisited[here] = true;

	for (int i = 0; i < NUM; ++i) {
		if (graph[here][i] && !isVisited[i])
			dfs(i);
	}
	
	ans.push_back(here);
}

void dfsAll()
{
	for (int i = 0; i < NUM; ++i) {
		if (aaa[i] && !isVisited[i])
			dfs(i);
	}
}

int alToNum(char ch) { return ch - 'a'; }

void makeGraph(const vector<string>& input)
{
	for (int sec = 1; sec < input.size(); ++sec) {
		int fir = sec - 1;
		int len = min(input[fir].size(), input[sec].size());
		for (int i = 0; i < len; ++i)
			if (input[fir][i] != input[sec][i]) {
				int a = input[fir][i] - 'a';
				int b = input[sec][i] - 'a';
				graph[a][b] = 1;
				aaa[a] = 1;
				aaa[b] = 1;
				break;
			}
	}
}

bool check(int N)
{
	for (int i = 0; i < ans.size(); ++i)
		for (int j = i + 1; j < ans.size(); ++j)
			if (graph[ans[j]][ans[i]])
				return false;
	return true;
}

void solve()
{
	int N;
	vector<string> input;
	string tmp;

	graph = vector<vector<int> >(NUM, vector<int>(NUM, 0));
	isVisited = vector<bool>(NUM, false);
	aaa = vector<int>(NUM, 0);
	ans.clear();

	scanf("%d", &N);
	for (int n = 0; n < N; ++n) {
		cin >> tmp;
		input.push_back(tmp);
	}
	makeGraph(input);
	dfsAll();
	reverse(ans.begin(), ans.end());

	if (!check(N)) printf("INVALID HYPOTHESIS");
	else {
		vector<bool> prt(NUM, true);
		for (int i = 0; i < ans.size(); ++i) {
			printf("%c", ans[i] + 'a');
			prt[ans[i]] = false;
		}
		for (int i = 0; i < NUM; ++i) {
			if (prt[i]) printf("%c", i + 'a');
		}
	}
	printf("\n");

}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
}