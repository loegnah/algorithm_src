#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

vector<string> ele = {
	"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al",
	"Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe",
	"Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr",
	"Y","Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb",
	"Te", "I", "Xe", "Cs", "Ba", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au",
	"Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Rf", "Db", "Sg",
	"Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Fl", "Lv", "La", "Ce", "Pr", "Nd",
	"Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Ac",
	"Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md",
	"No", "Lr"
};

vector<vector<string> > summEle(26);
vector<int> eleNum(26);
string input;
int inputLen;
int cache[50001];

void summerize() 
{
	for (int i = 0; i < ele.size(); ++i)
		if (ele[i].size() == 1) {
			eleNum[ele[i][0] - 0x41] = 1;
			summEle[ele[i][0] - 0x41].push_back(ele[i]);
		}
	for (int i = 0; i < ele.size(); ++i) {
		if (ele[i].size() == 2 && (!eleNum[ele[i][1] - 0x61] || !eleNum[ele[i][0]-0x41]))
			summEle[ele[i][0] - 0x41].push_back(ele[i]);
	}
}

bool canMake(int index)
{
	if (index >= inputLen) return 1;
	
	string tmp;
	int& isMatched = cache[index];
	if (isMatched != -1) return isMatched;

	isMatched = 0;
	int stChar = input[index] - 0x61;

	for (int i = 0; i < summEle[stChar].size(); ++i) {
		tmp = summEle[stChar][i];

		if (tmp.size() == 1) 
			isMatched = canMake(index + 1);
		else if (index+1 < inputLen && tmp[1] == input[index + 1]) 
			isMatched = canMake(index + 2);

		if (isMatched) break;
	}
	return isMatched;
	
}

int main(int *argc, char** argv)
{
	setbuf(stdout, NULL);
	summerize();

	int T;
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; ++testcase) {
		memset(cache, -1, sizeof(cache));
		cin >> input;
		inputLen = input.size();
		printf("Case #%d\n", testcase);
		if (canMake(0)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}