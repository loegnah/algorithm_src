#include <cstdio>
using namespace std;

const int MOD=15746;
int N;

int main() {
  scanf("%d",&N);
  int num[3] = {0,1,2};
  for(int i=3; i<=N; ++i) {
    int a=(i-2)%3, b=(i-1)%3, c=i%3;
    num[c] = (num[a]+num[b]) % MOD;
  }
  printf("%d",num[N%3]);
}
