#include <vector>
#include <algorithm>
using namespace std;

const int INT_MAX = 987654321;

struct RMQ {
	int n; // 배열 길이
	vector<int> rangeMin; // 각 구간의 최소치

	RMQ(const vector<int>& array) {
		n = array.size();
		rangeMin.resize(n*4);
		init(array, 0, n-1, 1);
	}

	int init(const vector<int>& array, int left, int right, int node) {
		if(left == right)
			return rangeMin[node] = array[left];

		int mid = (left + right) / 2;
		int leftMin = init(array, left, mid, node*2);
		int rightMin = init(array, mid+1, right, node*2+1);
		return rangeMin[node] = min(leftMin, rightMin);
	}

	int update(int index, int newValue,
				int node, int nodeLeft, int nodeRight) {
		
		// 안겹칠 때
		if(index < nodeLeft || nodeRight < index)
			return rangeMin[node];

		// 리프 노드까지 왔을 때
		if(nodeLeft == nodeRight)
			return rangeMin[node] = newValue;
		
		//걸칠 때
		int mid = (nodeLeft + nodeRight)/2;
		return min(update(index, newValue, node*2, nodeLeft, mid),
					update(index, newValue, node*2+1, mid+1, nodeRight));
	}

	int query(int left, int right,
				int node, int nodeLeft, int nodeRight) {
		
		// 안겹칠 때
		if(right < nodeLeft || nodeRight < left) 
			return INT_MAX;

		// 완전히 포함될 때
		if(left <= nodeLeft && nodeRight <= right) 
			return rangeMin[node];

		// 걸칠 때
		int mid = (nodeLeft+ nodeRight)/2;
		return min(query(left, right, node*2, nodeLeft, mid),
					query(left, right, node*2+1, mid+1, nodeRight));
		
	}
	
	// 외부 호출 용 인터페이스들
	int update(int index, int newValue) {
		return update (index, newValue, 1, 0, n-1);
	}
	int query(int left, int right) {
		return query (left, right, 1, 0, n-1);
	}

};

int main()
{

}
