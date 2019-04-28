#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;

const int ALPHABETS = 26;
int alToNum(char ch) { return ch - 'A';  }

class Trie {
public:
	Trie* children[ALPHABETS];
	int isEnd;
	int firstStr;
	
	Trie() : isEnd(false), firstStr(-1) { memset(children, 0, sizeof(children)); }
	~Trie() {
		for (int i = 0; i < ALPHABETS && children[i]; ++i)
			delete children[i];
	}

	void insert(const char* key, int strNum) {
		if (this->firstStr == -1)
			this->firstStr = strNum;
		if (*key == 0)
			isEnd = strNum;
		else {
			int next = alToNum(*key);
			if (children[next] == NULL)
				children[next] = new Trie();
			children[next]->insert(key + 1, strNum);
		}
	}
	
	Trie* find(const char* key) {
		if (*key == 0) return this;
		int next = alToNum(*key);
		if (children[next] == NULL) return NULL;
		return children[next]->find(key + 1);
	}
	
	int typing(const char* key, int id) {
		if (*key == 0) return 0;
		if (this->firstStr == id) return 1;
		int next = alToNum(*key);
		return 1 + children[next]->typing(key + 1, id);
	}
};

int N, M;

Trie* init() 
{
	vector<pair<int, string> > input;
	char strr[11];
	int prior;


	for (int i = 0; i < N; ++i) {
		scanf("%s %d", strr, &prior);
		input.push_back(make_pair(-prior, strr));
	}
	sort(input.begin(), input.end());

	Trie *dict = new Trie();
	for (int i = 0; i < N; ++i)
		dict->insert(input[i].second.c_str(),i);
	dict->firstStr = -1;
	return dict;
}

int solve()
{
	Trie* dict = init();
	char word[11];
	int ans = M-1;

	for (int i = 0; i < M; ++i) {
		scanf("%s", word);
		Trie* isFind = dict->find(word);
		if (isFind == NULL || isFind->isEnd == -1) ans += strlen(word);
		else ans += dict->typing(word, isFind->isEnd);
	}
	delete dict;
	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &M);
		printf("%d\n",solve());
	}
}