#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;

const int NMAX=100005;

struct FenwickTree {
	vector<long long> tree;

	FenwickTree(int n) : tree(n + 1) {}

	// 0~pos 까지 합
	long long sum(int pos) {
		long long ret = 0;
		++pos;

		while (pos > 0) {
			ret += tree[pos];
			pos &= (pos - 1); // 젤 마지막 1인 비트를 제거
		}
		return ret;
	}

	// 배열[pos]에 val 더함
	void add(int pos, int val) {
		++pos;
		while (pos < tree.size()) {
			tree[pos] += val;
			pos += (pos & -pos);
		}
	}
};

int N, cmds[NMAX], values[NMAX], maxKey;
long long arr[NMAX*2];
vector<string> all_keys, key1_str, key2_str;
map<string,int> realKeys;

bool cmp (const string& a, const string& b) {
    if(a.size() == b.size()) return a<b?true:false;
    else return a.size()<b.size() ? true:false;
}

void input_init()
{
    cin >> N;
    key1_str = vector<string>(N+1);
    key2_str = vector<string>(N+1);

    for(int i=0; i<N; ++i) {
        cin >> cmds[i] >> key1_str[i];
        all_keys.push_back(key1_str[i]);
        if(cmds[i] == 1) cin >> values[i];
        else if(cmds[i] == 2) {
            cin >> key2_str[i];
            all_keys.push_back(key2_str[i]);
        }
    }
}

void keySort()
{
    sort(all_keys.begin(),all_keys.end(),cmp);

    realKeys.clear();
    int realKey = 1;

    for(auto key : all_keys) {
        if(realKeys[key]) continue;
        realKeys[key] = realKey++;
    }
    maxKey = realKey;
}

void solve()
{
    string ans = "";
    int maxKeyDouble = maxKey*2;
    FenwickTree fw(maxKeyDouble+1);

    memset(arr,0,sizeof(arr));

    for(int i=0; i<N; ++i) {
        int cmd = cmds[i], key1 = realKeys[key1_str[i]];
        int value = 0, key2 = 0;
        if(cmd == 1) {
            value = values[i];
            arr[key1] += value;
            fw.add(key1,value);
            ans += to_string(fw.sum(maxKeyDouble));
        }
        else if(cmd == 2) {
            key2 = realKeys[key2_str[i]];
            ans += to_string(fw.sum(key2)-fw.sum(key1-1));
        }
        else {
            fw.add(key1,-arr[key1]);
            arr[key1] = 0;
            ans += to_string(fw.sum(maxKeyDouble));
        }
        ans += " ";
    }
    cout << ans << endl;
}

int main()
{
    input_init();
    keySort();
    solve();
}
