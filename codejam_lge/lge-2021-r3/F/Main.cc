// n stepping stumps
// # of ways to arrange (or find 'any')
#include<vector>
#include<cstdio>
#include<map>
#include<set>
#include<cstring>
#include<cstring>
#include<memory>
#include<algorithm>
#include<string>
#include<iostream>
#include<queue>
using namespace std;
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORE(it,x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); ++it)
typedef long long ll;

const int maxn = 512;
class P6 {
	int n;
	int dp[maxn][maxn][2][2], fr[maxn][maxn][2][2];
	// 0 = a < b
	// 1 = a > b

	vector<vector<int> > d;
	public:
	bool ok(int todo, int i, int j) {
		if(d[i][0] >= d[j][0]) return false;
		if(i == 0 && j == n) return false;
		return i == 0
		|| (todo == 0 && d[i][1] < d[j][1])
		|| (todo == 1 && d[i][1] > d[j][1]);
	}
	int doit(int i, int j, int x, int y) {
		if(i == 0 && j == 1) return 1;
		int& ret = dp[i][j][x][y];
		if(ret != -1) return ret;
		ret = 0;

		if(i+1 == j) {
			for(int k = 0; k < i; k++) {
				if(ok(1-y, k, j)) {
					ret = doit(k, i, 1-y, x);
					if(ret) {
						fr[i][j][x][y] = k;
						break;
					}
				}
			}
		}
		else {
			if(ok(1-y, j-1, j)) {
				ret = doit(i, j-1, x, 1-y);
				if(ret) {
					fr[i][j][x][y] = j-1;
				}
			}
		}
		return ret;
	}

	void pc(int i, int j, int x, int y) {
		printf("dp[%d %d %d %d] -> %d\n", i, j, x, y, dp[i][j][x][y]);
	}

	vector<int> dodp(vector<vector<int> > v) {
		n = v.size();
		d.resize(n+1);
		for(int i = 0; i <= n; i++) {
			d[i].resize(3);
			if(i > 0) {
				d[i][0] = v[i-1][0];
				d[i][1] = v[i-1][1];
				d[i][2] = i;
			}
		}
		sort(d.begin(), d.end());

		memset(dp, -1, sizeof(dp));
		memset(fr, -1, sizeof(fr));
		FOR(i,1,n) FOR(x,0,2)
			if(doit(i, n, x, 1-x) == 1 && ok(x, i, n)) {
				int y = 1-x, j = n, sig = 0;
				vector<int> p[2];
				while(true) {
					int k = fr[i][j][x][y];
					p[1-sig].push_back(j);
					if(k == -1) break;
					if(i+1 == j) {
						sig = 1-sig;
						j = i;
						i = k;
						int tmp = x;
						x = 1-y;
						y = tmp;
					} else {
						j--;
						y = 1-y;
					}
				}

				vector<int> ans;
				for(vector<int>::reverse_iterator it = p[0].rbegin(); it != p[0].rend(); ++it)
					ans.push_back(d[*it][2]);
				FORE(it, p[1]) ans.push_back(d[*it][2]);
				return ans;
			}
      return vector<int>();
	}

};

void print(vector<int>& ans) {
	if(ans.size() == 0) printf("-1\n");
	else {
		FORE(it, ans) printf("%d ", *it);
		printf("\n");
	}
}
int checker(vector<vector<int>>& v, vector<int> ans) {
	if(ans.size() == 0) return 0;
	int n = v.size();
	// Check height
	bool has_peak = false;
	for(int i = 1; i < n-1; i++) {
		int h1 = v[ans[i-1]-1][0];
		int h2 = v[ans[i]-1][0];
		int h3 = v[ans[i+1]-1][0];
		if(h1 < h2 && h2 > h3) {
			has_peak = true;
			// INC
			for(int j = 0; has_peak && j < i; j++)
				if(v[ans[j]-1][0] >= v[ans[j+1]-1][0]) has_peak = false;
			// DEC
			for(int j = i+1; has_peak && j < n; j++)
				if(v[ans[j-1]-1][0] <= v[ans[j]-1][0]) has_peak = false;

			break;
		}
	}
	if(!has_peak) return -1;
	// Check radius
	for(int i = 1; i < n-1; i++) {
		int r1 = v[ans[i-1]-1][1];
		int r2 = v[ans[i]-1][1];
		int r3 = v[ans[i+1]-1][1];
		if((r1 < r2 && r2 > r3) || (r1 > r2 && r2 < r3));
		else
			return -1;
	}

	return 1;
}

int main() {
	int t;
	scanf("%d", &t);
	P6* ins = new P6();
	while(t--) {
		int n;
		vector<vector<int > > v;
		scanf("%d", &n);
		v.resize(n);
		for(int i = 0; i < n; i++) v[i].resize(2);
		FOR(i,0,n) scanf("%d", &v[i][0]); // hei
		FOR(i,0,n) scanf("%d", &v[i][1]); // rad

		vector<int> ans1 = ins->dodp(v);
		
		print(ans1);
		
		int c1 = checker(v, ans1);
		if(c1 == -1) {
			printf("data: n = %d\n", n);
			FORE(it, v) printf("(%2d %2d) ", (*it)[0], (*it)[1]); printf("\n");

			printf("--------------------------- WTF\n");
			return -1;
		}
	}

	return 0;
}

