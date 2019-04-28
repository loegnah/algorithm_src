#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int SZ = 'z' - 'a' + 1;

void solve() {
    string ipt,out;
    int alp[SZ][SZ+1];
   
    memset(alp,0,sizeof(alp)); 
    cin >> ipt;
    for(int i=0; i<ipt.size(); i+=2) {
	int cur = ipt[i]-'a';
	if(i == ipt.size()-1) {
	    alp[cur][SZ]++;
	    break;
	}
	int nxt = ipt[i+1]-'a';
	alp[cur][nxt]++;
    }
    for(int i=0; i<SZ; ++i) {
	for(int a=0; a<alp[i][SZ]; ++a)
	    out += 'a'+i;
	for(int j=0; j<SZ; ++j)
	    for(int k=0; k<alp[i][j]; ++k) {
		out += 'a'+i;
		out += 'a'+j;
	    }
    }
    cout << out << endl;
}

int main()
{
    int T;
    cin >> T;
    while(T--) {
	solve();
    }

}
