#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s;
  cin >> s;
  for(int i=0; i<s.size(); ++i)
    printf("%d ",s[i]-'A'+1);

}
