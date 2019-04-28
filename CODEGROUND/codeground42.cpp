/* 부분배열 문제
  연속된 값이어야된다. 부분 '수열'하고 '배열'은 다른듯.
  100점 */
#include <cstdio>
#include <cstring>
using namespace std;

int t,s,n,ipt;
int sum[100002];

int main()
{
  setbuf(stdout,NULL);
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    scanf("%d %d",&n,&s);
    memset(sum,0,sizeof sum);
    for(int i=1; i<=n; ++i) {
      scanf("%d",&ipt);
      sum[i] = sum[i-1]+ipt;
    }
    int j=0, minLen = 111111;
    for(int i=1; i<=n; ++i) {
      if(sum[i]-sum[j] < s) continue;
      while(sum[i]-sum[j] >= s) j++;
      j--;
      if(minLen > i-j) minLen = i-j;
    }
    if(minLen == 111111) minLen = 0;
    printf("#testcase%d\n%d\n",tc,minLen);
  }
}
