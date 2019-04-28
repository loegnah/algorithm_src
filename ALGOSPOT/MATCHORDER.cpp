#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int C, N, rus[101], kor[101];

	scanf("%d", &C);
	for (int test = 0; test < C; ++test) {
		scanf("%d", &N);
		for (int n = 0; n < N; ++n) scanf("%d", rus + n);
		for (int n = 0; n < N; ++n) scanf("%d", kor + n);

		sort(rus, rus + N);
		sort(kor, kor + N);

		int ct = 0, st = 0;
		bool check = true;
		for (int a = 0; a < N; ++a) {
			for (int b = st; b < N; ++b) {
				if (rus[a] <= kor[b]) {
					ct++;
					st = b+1;
					check = false;
					break;
				}
			}
			if (check) break;
		}
		printf("%d\n", ct);
	}
}