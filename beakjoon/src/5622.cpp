#include <cstdio>
using namespace std;

int main()
{
  const int bound[8] {'C','F','I','L','O','S','V','Z'};
  int ans = 0;
  char s[20];
  scanf("%s",s);
  for(int i=0; s[i]; ++i)
    for(int k=0; k<8; ++k)
      if(s[i] <= bound[k]) {
        ans += k+3;
        break;
  }
  printf("%d",ans);
}
