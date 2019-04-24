#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int CY[4] = { 1,0,-1,0 };
const int CX[4] = { 0,1,0,-1 };

int N, L, R;
int ppl[51][51];
bool isChecked[51][51];
vector<int> y_list, x_list;

inline int _abs(int a) {
	return a > 0 ? a : -a;
}

void bfs(int y, int x)
{
	int ny, nx, dif;
	isChecked[y][x] = true;
	y_list.push_back(y);
	x_list.push_back(x);

	for (int i = 0; i < 4; ++i) {
		ny = y + CY[i];
		nx = x + CX[i];
		dif = _abs(ppl[ny][nx] - ppl[y][x]);
		if (ny < N && ny >= 0 && nx < N && nx >= 0 &&
			!isChecked[ny][nx] && dif >= L && dif <= R) {
			bfs(ny, nx);
		}
	}
}

void change_ppl()
{
	int sum = 0;
	for (int i = 0; i < (int)y_list.size(); ++i)
		sum += ppl[y_list[i]][x_list[i]];
	sum /= (int)y_list.size();

	for (int i = 0; i < (int)y_list.size(); ++i)
		ppl[y_list[i]][x_list[i]] = sum;
}

void print_ppl()
{
	printf("\n");
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) printf("%d ", ppl[y][x]);
		printf("\n");
	}
}

int solve()
{
	bool isChanged;
	int ans = 0;

	while (true) {
		memset(isChecked, 0, sizeof(isChecked));
		isChanged = false;

		for (int y = 0; y < N; ++y) for (int x = 0; x < N; ++x) {
			if (!isChecked[y][x]) {
				y_list.clear();
				x_list.clear();
				bfs(y, x);
				if ((int)y_list.size() > 1) {
					isChanged = true;
					change_ppl();
				}
			}
		}
		if (!isChanged) break;
		ans++;
		//print_ppl();
	}
	return ans;
}

int main()
{
	scanf("%d %d %d", &N, &L, &R);
	for (int y = 0; y < N; ++y) for (int x = 0; x < N; ++x)
		scanf("%d", &ppl[y][x]);

	printf("%d\n", solve());
}