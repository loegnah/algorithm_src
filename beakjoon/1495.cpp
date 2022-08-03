#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,s,m;
int v[102];
int cache[102][1002];

int dp(int song,int vol)
{
  if(vol<0 || vol>m) return -2;
  if(song == n) {
    if(vol<0 || vol>m) return -2;
    else return vol;
  }
  int& ret = cache[song][vol];
  if(ret != -1) return ret;
  ret = max(dp(song+1, vol-v[song]),dp(song+1,vol+v[song]));
  return ret;
}

int main()
{
  memset(cache,-1,sizeof cache);
  scanf("%d %d %d",&n,&s,&m);
  for(int i=0; i<n; ++i) scanf("%d",v+i);
  int ans = dp(0,s);
  if(ans < 0) printf("-1");
  else printf("%d",ans);
}
