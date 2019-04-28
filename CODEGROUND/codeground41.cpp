#include <cstdio>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
  if(b>a) return gcd(b,a);
  while(b) {
    ll tmp = b;
    b = a%b;
    a = tmp;
  }
  return a;
}

int main(int argc, char** argv)
{
  int t;
  setbuf(stdout,NULL);
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    char p[15] = "";
    int ans[6] = {0,0,0,0,0,0};
    scanf("%s",p);
    ll a = p[0]-'0';    // p를 정수화 하였을 때의 값이됨.
    ll b = 1;           // p를 정수화할 때 곱해지는 값이됨.
    for(int i=1; p[i]; ++i) {
      if(p[i] == '.') continue;
      a *= 10;
      b *= 10;
      a += p[i]-'0';
    }
    ll g = gcd(a,b);
    a = a/g; b = b/g;
    ll c = 5;
    while(b) {
      if(a==b) {
        ans[1] += b;
        break;
      }
      if(a-c>=b-1) {
        ans[c]++;
        a-=c;
        b--;
      }
      else c--;
    }
    printf("#testcase%d\n%d %d %d %d %d\n",tc,ans[1],ans[2],ans[3],ans[4],ans[5]);
  }
}
