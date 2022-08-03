#include <cstdio>
using namespace std;

const int RM_NODE = -2;
int n,parent[52],rm;
bool haveChild[52];

int main()
{
  scanf("%d",&n);
  for(int i=0; i<n; ++i) scanf("%d",parent+i);
  for(int i=0; i<n; ++i) haveChild[i] = false;
  scanf("%d",&rm);
  parent[rm] = RM_NODE;
  for(int i=0; i<n; ++i) {
    int pi = parent[i];
    while(1) {
      if(pi == -2) {
        haveChild[i] = true;
        break;
      }
      if(pi == -1) {
        haveChild[parent[i]] = true;
        break;
      }
      pi = parent[pi];
    }
  }
  int ans =0;
  for(int i=0; i<n; ++i)
    if(!haveChild[i]) ans++;
  printf("%d\n",ans);
}
