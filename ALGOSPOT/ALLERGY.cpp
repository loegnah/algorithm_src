#include <iostream>
#include <map>
#include <cstring>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;

const int INF = 987654321;
int N, M;
map<string, int> nameidx;
int canEat[21];
int cache[21][1 << 21];

int game(int foodidx, int person)
{
	if (person == (1 << N) - 1) return 0;
	if (foodidx == M) return INF;
	
	int &ret = cache[foodidx][person];
	if (ret != -1) return ret;

	ret = INF;
	int nextPerson = person + canEat[foodidx];
	for (int next = foodidx + 1; next < M; ++next)
		ret = min(ret, 1 + game(next,nextPerson));
	return ret;
}

int main()
{
	int T, tmp, ret;
	string name;
	
	cin >> T;
	for (int test = 0; test < T; ++test)
	{
		//reset
		nameidx.clear();
		memset(canEat, 0, sizeof(canEat));
		memset(cache, -1, sizeof(cache));

		cin >> N >> M;
		for (int i = 0; i < N; ++i) {
			cin >> name;
			nameidx.insert(pair<string,int>(name,i));
		}
		for (int i = 0; i < M; ++i) {
			cin >> tmp;
			for (int j = 0; j < tmp; ++j) {
				cin >> name;
				canEat[i] += (1 << nameidx[name]);
			}
		}

		ret = INF;
		for (int i = 0; i < M; ++i) 
			ret = min(ret,game(i, 0));
		cout << ret << endl;
		

	}
}