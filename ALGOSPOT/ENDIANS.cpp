#include <iostream>
using namespace std;

const unsigned int BIT8 = (1 << 8) - 1;

unsigned int solve() {
	unsigned int n, ret = 0;
	scanf("%u", &n);

	for (int i = 0; i < 4; ++i) {
		int move = i * 8;
		unsigned int m = (n >> move) & BIT8;
		ret += (m << (24 - move));
	}

	return ret;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--)
		printf("%u\n", solve());
}