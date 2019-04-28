#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n,m,k,a,b,ai[12],bi[12],used[1005][2];
int a_using, b_using;
vector<pair<int,int> > tk,a_process,b_process;
queue<int> a_wait,b_wait;

void input()
{
  int i,j,tmp;
  pair<int,int> pTmp(0,0);

  scanf("%d %d %d %d %d",&n,&m,&k,&a,&b);

  // 초기화
  tk.resize(k);
  a_process.resize(n+1); b_process.resize(m+1);
  a_wait = queue<int>();
  b_wait = queue<int>();
  a_using = b_using = 0;
  for(i=1; i<=n; ++i) a_process[i] = pTmp;
  for(j=1; j<=m; ++j) b_process[j] = pTmp;

  for(i=1; i<=n; ++i) scanf("%d",ai+i);
  for(i=1; i<=m; ++i) scanf("%d",bi+i);
  for(i=1; i<=k; ++i) {
    scanf("%d",&tmp);
    tk[i-1] = make_pair(tmp,i);
  }

  sort(tk.begin(),tk.end());
}

int solve()
{
  int i,j,ps = 0,complete = 0, curTime = 0;
  while(true) {
    while(ps<k && tk[ps].first==curTime) a_wait.push(tk[ps++].second);

    for(i=1; i<=n; ++i) {
      if(a_process[i].first>0) {
        a_process[i].first--;
        if(a_process[i].first==0) {
          b_wait.push(a_process[i].second);
          used[a_process[i].second][0] = i;
          a_using--;
        }
      }
    }

    for(i=1; i<=n && a_using<n && !a_wait.empty(); ++i) {
      if(a_process[i].first==0) {
        a_process[i] = make_pair(ai[i],a_wait.front());
        a_wait.pop();
        a_using++;
      }
    }

    for(j=1; j<=m; ++j) {
      if(b_process[j].first>0) {
        b_process[j].first--;
        if(b_process[j].first==0) {
          used[b_process[j].second][1] = j;
          complete++;
          b_using--;
        }
      }
    }

    for(j=1; j<=m && b_using<m && !b_wait.empty(); ++j) {
      if(b_process[j].first==0) {
        b_process[j] = make_pair(bi[j],b_wait.front());
        b_wait.pop();
        b_using++;
      }
    }

    if(complete==k) break;
    curTime++;
  }
}

int calc_ans()
{
  int ans =0;
  for(int i=1; i<=k; ++i) {
    if(used[i][0]==a && used[i][1] == b)
      ans += i;
  }
  return ((ans==0)?-1:ans);
}

int main()
{
  int t;
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    input();
    solve();
    printf("#%d %d\n",tc,calc_ans());
  }
}
