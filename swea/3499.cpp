#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> dk1,dk2;

int main()
{
  int t,n;
  cin >> t;
  for(int tc=1; tc<=t; ++tc) {
    cin >> n;
    dk1.resize((n+1)/2); dk2.resize(n/2);
    for(int i=0; i<(n+1)/2; ++i) cin >> dk1[i];
    for(int i=0; i<n/2; ++i) cin >> dk2[i];
    cout << "#" << tc << " ";
    for(int i=0; i<n/2; ++i) cout << dk1[i] << " " << dk2[i] << " ";
    if(n%2) cout << dk1[n/2] << "\n";
    else cout << "\n";
  }
}
