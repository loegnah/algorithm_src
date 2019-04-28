#include <cstdio>
#include <cstring>
using namespace std;

int n,ans;
bool row[11],ldg[21],rdg[21];

void queen(int c)
{
  if(c==n) { ans++; return; }

  for(int r=0; r<n; ++r) {
    if(row[r] && ldg[r+c] && rdg[n-1-c+r]) {
      row[r] = false; ldg[r+c] = false; rdg[n-1-c+r] = false;
      queen(c+1);
      row[r] = true; ldg[r+c] = true; rdg[n-1-c+r] = true;
    }
  }
}

int main()
{
  int t;
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    scanf("%d",&n);

    memset(row,-1,sizeof row);
    memset(ldg,-1,sizeof ldg);
    memset(rdg,-1,sizeof rdg);
    ans = 0;

    queen(0);
    printf("#%d %d\n",tc,ans);
  }
}
