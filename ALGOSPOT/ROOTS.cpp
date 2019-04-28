#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


double calcValue(vector<double>& ind, double mid)
{
	double ret = 0;
	for (int i = 0; i < ind.size(); ++i)
		ret += ind[i] * pow(mid, i);
	return ret;
}

vector<double> calcRoot(vector<double> ind)
{
	int indSize = ind.size();

	vector<double> ret;
	ret.push_back(-10.1);

	if (indSize == 2) {
		ret.push_back(-1 * ind[0] / ind[1]);
	}
	else {
		vector<double> tmp;
		for (int i = 1; i < indSize; ++i)
			tmp.push_back(ind[i] * i);

		double lo, hi, mid, value;
		vector<double> pre = calcRoot(tmp);

		for (int i = 0; i < pre.size() - 1; ++i) {
			lo = pre[i];
			hi = pre[i + 1];
			if (calcValue(ind, lo) > calcValue(ind, hi))
				swap(lo, hi);
			for (int acc = 0; acc < 100; ++acc) {
				mid = (lo + hi) / 2;
				value = calcValue(ind, mid);

				if (value > 0)
					hi = mid;
				else
					lo = mid;
			}
			ret.push_back(mid);
		}
	}
	ret.push_back(10.1);
	sort(ret.begin(), ret.end());
	return ret;

}

vector<double> solve(vector<double>& input)
{
	vector<double> tmpAns = calcRoot(input);
	vector<double> ans;
	ans.resize(tmpAns.size() - 2);
	for (int i = 0; i < ans.size(); ++i)
		ans[i] = tmpAns[i + 1];
	return ans;
}


int main()
{
	int C;
	scanf("%d", &C);
	for (int tc = 0; tc < C; ++tc) {
		int N;
		scanf("%d", &N);

		vector<double> input;
		input.resize(N+1);

		double tmp;
		for (int n = N; n >= 0; --n) {
			scanf("%lf", &tmp);
			input[n] = tmp;
		}
		vector<double> ans = solve(input);
		//printf("%d", ans.size());
		for (int i = 0; i < ans.size(); ++i)
			printf("%1.12lf ", ans[i]);
		printf("\n");
	}
}