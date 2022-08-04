#include <bits/stdc++.h>
using namespace std;

struct DICE {
	char A[6][9];

	static void copyFace(char A[9], const char B[9]) {
		memcpy(A, B, 9 * sizeof(char));
	}

	static void cycleFour(char &a, char &b, char &c, char &d) {
		swap(a, b); swap(b, c); swap(c, d);
	}

	static void rotLFace(char A[9]) {
		cycleFour(A[0], A[2], A[8], A[6]);
		cycleFour(A[1], A[5], A[7], A[3]);
	}

	static void rotRFace(char A[9]) {
		cycleFour(A[0], A[6], A[8], A[2]);
		cycleFour(A[1], A[3], A[7], A[5]);
	}

	static void cdotSwap(char A[9]) {
		swap(A[0], A[8]); swap(A[1], A[7]);
		swap(A[2], A[6]); swap(A[3], A[5]);
	}

	DICE alpha() const {
		DICE r;

		copyFace(r.A[0], A[4]);
		copyFace(r.A[1], A[0]);
		copyFace(r.A[2], A[2]);
		copyFace(r.A[3], A[3]);
		copyFace(r.A[4], A[5]);
		copyFace(r.A[5], A[1]);

		rotLFace(r.A[2]);
		rotRFace(r.A[3]);

		return r;
	}

	DICE invAlpha() const {
		DICE r = alpha();
		r = r.alpha();
		r = r.alpha();
		return r;
	}

	DICE beta() const {
		DICE r;

		copyFace(r.A[0], A[3]);
		copyFace(r.A[1], A[1]);
		copyFace(r.A[2], A[0]);
		copyFace(r.A[3], A[5]);
		copyFace(r.A[4], A[4]);
		copyFace(r.A[5], A[2]);

		rotRFace(r.A[1]);
		rotLFace(r.A[4]);

		cdotSwap(r.A[3]);
		cdotSwap(r.A[5]);

		return r;
	}

	DICE invBeta() const {
		DICE r = beta();
		r = r.beta();
		r = r.beta();
		return r;
	}

	DICE gamma() const {
		DICE r = invAlpha();
		r = r.beta();
		r = r.alpha();
		return r;
	}

	DICE invGamma() const {
		DICE r = invAlpha();
		r = r.invBeta();
		r = r.alpha();
		return r;
	}

	string getTerm() const {
		string S;
		for(int i = 0; i < 6; i++) {
			for(int j = 0; j < 9; j++)
				S += A[i][j];
		}
		return S;
	}

	string getNorm() const {
		DICE r = alpha();
		string S = r.getTerm();

		for(int i = 0; i < 3; i++) {
			r = r.alpha();
			S = min(S, r.getTerm());
		}

		for(int j = 0; j < 3; j++) {
			r = r.beta();
			for(int i = 0; i < 4; i++) {
				r = r.alpha();
				S = min(S, r.getTerm());
			}
		}

		r = r.alpha().beta();
		for(int i = 0; i < 4; i++) {
			r = r.alpha();
			S = min(S, r.getTerm());
		}

		r = r.beta().beta();
		for(int i = 0; i < 4; i++) {
			r = r.alpha();
			S = min(S, r.getTerm());
		}

		return S;
	}
};

char A[1005][1005];

int H, W;

bool isValidCorner(int i, int j) {
	const char c = A[i][j];
	return '+' == c || 'O' == c;
}

bool isValidFace(int i, int j) {
	return isValidCorner(i, j)
		&& isValidCorner(i, j+4)
		&& isValidCorner(i+4, j)
		&& isValidCorner(i+4, j+4)
		&& '-' == A[i][j+2]
		&& '-' == A[i+4][j+2]
		&& '|' == A[i+2][j]
		&& '|' == A[i+2][j+4];
}

void makeDice(int i, int j, DICE &r) {
	if(i < 1 || j < 1 || H < i+4 || W < j+4) return;
	if(!isValidFace(i, j)) return;
	if('+' != A[i][j] && '+' != A[i][j+4] && '+' != A[i+4][j] && '+' != A[i+4][j+4]) return;

	A[i][j] = A[i][j+4] = A[i+4][j] = A[i+4][j+4] = 'O';

	memcpy(r.A[3]  , A[i+3]+j+1, 3 * sizeof(char));
	memcpy(r.A[3]+3, A[i+2]+j+1, 3 * sizeof(char));
	memcpy(r.A[3]+6, A[i+1]+j+1, 3 * sizeof(char));

	r = r.invBeta();
	makeDice(i+4, j, r);
	r = r.beta();

	r = r.gamma();
	makeDice(i, j-4, r);

	r = r.gamma().gamma();

	makeDice(i, j+4, r);
	r = r.gamma();
}

vector<int> solution(int _H, int _W, vector<string> _A) {
	H = _H; W = _W;
	for(int i = 1; i <= H; i++)
		for(int j = 1; j <= W; j++)
			A[i][j] = _A[i-1][j-1];
	
	vector<string> V;
	for(int i = 1; i <= H; i++) for(int j = 1; j <= W; j++)
		if('+' == A[i][j]) {
			DICE r;
			makeDice(i, j, r);
			string S = r.getNorm();
			V.emplace_back(S);
		}
	
	sort(V.begin(), V.end());

	vector<int> ret;
	for(int s = 0, n = V.size(); s < n;) {
		int e = s+1;
		while(e < n && V[s] == V[e]) e++;
		ret.emplace_back(e-s);
		s = e;
	}

	sort(ret.begin(), ret.end());
	reverse(ret.begin(), ret.end());

	return ret;
}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
        vector<int> ans = solution(n, m, a);
        for (int i=0; i<ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    return 0;
}