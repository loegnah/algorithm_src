#include<cassert>
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
#define pb push_back
typedef long long ll;


class Sol {
  public:
  
  int gcd(int x, int y) {
    while(y > 0) {
      int z = x % y;
      x = y;
      y = z;
    }
    return x;
  }
  
  int solve(int a, int b, int c) {
    int g = gcd(a, b);
    return c/g;
  }
};

int main() {
	Sol* ins = new Sol();  
  int t;
  scanf("%d", &t);
  
  while(t--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int ans = ins->solve(a, b, c);
    printf("%d\n", ans);
  }
	return 0;
}
