#include <cstdio>
using namespace std;

const char award[10][3] = {"A+","A0","A-","B+","B0","B-","C+","C0","C-","D0"};

int main()
{
  int T,tc=1,N,K,score[101],a,b,c;
  for(scanf("%d",&T); tc<=T; ++tc) {
    scanf("%d %d",&N, &K);
    for(int i=1; i<=N; ++i) {
      scanf("%d %d %d",&a,&b,&c);
      score[i] = (a*35*3 + b*45*3 + c*20*3)/3;
    }
    int cache = score[K], ans = 0;
    for(int i=1; i<=N; ++i) {
      if(score[i] > cache) ans++;
    }
    printf("#%d %s\n",tc,award[ans/(N/10)]);
  }
}
