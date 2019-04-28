#include <iostream>
#include <stack>
#include <string>
using namespace std;

const string openStr = "({[";
const string closeStr = ")}]";
string input;
char curCh;
bool solve()
{
	stack<char> strStack;
	string::iterator pInput = input.begin();
	while (pInput != input.end()) {
		curCh = *pInput;
		if (openStr.find(curCh) != string::npos) strStack.push(curCh);
		else if (strStack.empty()) return false;
		else if (openStr.find(strStack.top()) != closeStr.find(curCh)) return false;
		else strStack.pop();
		pInput++;
	}
	if (strStack.empty()) return true;
	return false;
}

int main()
{
	int T;
	cin >> T;
	for (int tc = 0; tc < T; ++tc) {
		cin >> input;
		if (solve()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}