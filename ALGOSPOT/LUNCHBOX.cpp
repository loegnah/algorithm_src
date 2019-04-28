#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
	int C, N, tmp;
	vector<pair<int, int> > time(10001);

	scanf("%d", &C);
	for (int test = 0; test < C; ++test) {
		scanf("%d", &N);
		
		int tot = 0;
		for (int i = 0; i < N; ++i) {
			scanf("%d", &tmp);
			tot += tmp;
			time[i].second = tmp;
		}
		for (int i = 0; i < N; ++i) {
			scanf("%d", &tmp);
			time[i].first = tmp;
		}
		sort(time.begin(), time.begin()+N);
		int ret = 0, microTime = 0;
		for (int i = N - 1; i >= 0; --i) {
			microTime += time[i].second;
			ret = max(ret, microTime + time[i].first);
		}
		printf("%d\n", ret);
		

	}
}