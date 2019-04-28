#include <cstdio>
#include <vector>
using namespace std;

vector<int> cache;

void preSetting()
{
  int a = 0;
  for(int i=1; a<=500000; ++i) {
    a += i;
    cache.push_back(a);
  }
}

int main()
{
  int t,p,q;
  preSetting();
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    scanf("%d %d",&p,&q);
    int px,py,qx,qy,newx,newy;
    for(int i=0; i<cache.size(); ++i)
      if(p<=cache[i]) { px = (i+1)-(cache[i]-p); py = (cache[i]-p+1); break;}
    for(int i=0; i<cache.size(); ++i)
      if(q<=cache[i]) {qx = (i+1)-(cache[i]-q); qy = (cache[i]-q+1); break;}
    newx = px+qx; newy = py+qy;
    printf("#%d %d\n",tc,cache[newx+newy-2]-(newy-1));
  }
}
