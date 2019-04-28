#include <iostream>
#include <string>
#include <iterator>
using namespace std;

int main()
{
    int T;
    string ipt;
    cin >> T;
    while(T--) {
	cin >> ipt;
	string front, behind;
	auto iter = ipt.begin();
	for(int i=0; i<ipt.size(); ++i, iter++) {
	    if(i%2==0) front += *iter;
	    else behind += *iter;
	}
	cout << front << behind << endl;
    }
}
