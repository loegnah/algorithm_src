#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

const string xCng = "X+YF";
const string yCng = "FX-Y";
const string initStr = "FX";
int PMAX = 1000000000 + 500;
int N, P, L;
int genLength[51];

void calcLength();
char findChar(const string &str, int skip, int generation);

int main()
{
	int C;

	scanf("%d", &C);
	calcLength();
	while (C--) {
		scanf("%d %d %d", &N, &P, &L);
		for(int i=0; i<L; ++i)
			printf("%c", findChar(initStr, P+i-1, N));
		printf("\n");
	}
}

void calcLength() {
	genLength[0] = 1;
	for (int i = 1; i <= 50; ++i) 
		genLength[i] = min(PMAX, 2 * genLength[i - 1] + 2);
}

char findChar(const string &str, int skip, int generation) {
	if (generation == 0) 
		return str[skip];
	
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == 'X' || str[i] == 'Y') {
			if (skip >= genLength[generation])
				skip -= genLength[generation];
			else if (str[i] == 'X')
				return findChar(xCng, skip, generation - 1);
			else if (str[i] == 'Y')
				return findChar(yCng, skip, generation - 1);
		}
		else if (skip == 0)
			return str[i];
		else
			skip -= 1;
	}
}