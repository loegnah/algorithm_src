#include <cstdio>
#include <cstring>
using namespace std;

bool ck[500005];

int main()
{
  memset(ck,0,sizeof ck);
  for(int i=3; i<=1000; i+=2) {
    int j = 3;
    int n = i*j;
    while(n<=1000000) {
      ck[n/2] = true;
      j += 2;
      n = i*j;
    }
  }
  printf("2 ");
  for(int n=3; n<=1000000; n+=2) {
    if(!ck[n/2]) printf("%d ",n);
  }
}
