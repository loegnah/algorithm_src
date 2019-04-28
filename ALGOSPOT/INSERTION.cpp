#include <iostream>
#include <ctime>
#include <utility>
using namespace std;

#include <iostream>
#include <ctime>
#include <utility>
using namespace std;

// Treap Class
template<class TYPE = int>
class Node
{
public:
	TYPE key;
	int priority, size;
	Node *lNode, *rNode;

	Node(const TYPE& _key) : key(_key), priority(rand()),
		size(1), lNode(nullptr), rNode(nullptr) { }

	void setLeft(Node* newLNode) { lNode = newLNode; renewSize(); }
	void setRight(Node* newRNode) { rNode = newRNode; renewSize(); }

	void renewSize() {
		size = 1;
		if (lNode != nullptr) size += lNode->size;
		if (rNode != nullptr) size += rNode->size;
	}

	typedef pair<Node*, Node*> NodePair;
	static NodePair split(Node* root, TYPE newKey) {
		if (root == nullptr) return NodePair(nullptr, nullptr);

		if (root->key < newKey) {
			NodePair rPartial = split(root->rNode, newKey);
			root->setRight(rPartial.first);
			return NodePair(root, rPartial.second);
		}
		NodePair lPartial = split(root->lNode, newKey);
		root->setLeft(lPartial.second);
		return NodePair(lPartial.first, root);
	}

	static Node* insert(Node* root, Node* inNode) {
		if (root == nullptr) return inNode;

		if (root->priority < inNode->priority) {
			NodePair spt = split(root, inNode->key);
			inNode->setLeft(spt.first);
			inNode->setRight(spt.second);
			return inNode;
		}

		if (root->key < inNode->key)
			root->setRight(insert(root->rNode, inNode));
		else
			root->setLeft(insert(root->lNode, inNode));
		return root;
	}

	static Node* merge(Node* a, Node* b) {
		if (a == nullptr) return b;
		if (b == nullptr) return a;
		if (a->priority < b->priority) {
			b->setLeft(merge(a, b->lNode));
			return b;
		}
		a->setRight(merge(a->rNode, b));
		return a;
	}

	static Node* erase(Node* root, TYPE delKey) {
		if (root == nullptr) return root;
		if (root->key == delKey) {
			Node* newRoot = merge(root->lNode, root->rNode);
			delete root;
			return newRoot;
		}
		if (root->key < delKey)
			root->setRight(erase(root->rNode, delKey));
		else
			root->setLeft(erase(root->lNode, delKey));
		return root;
	}

	static Node* findKth(Node* root, int k) {
		int leftSize = 0;
		if (root->lNode != nullptr) leftSize = root->lNode->size;

		if (leftSize >= k) return findKth(root->lNode, k);
		if (leftSize + 1 == k) return root;
		return findKth(root->rNode, k - leftSize - 1);
	}

	static int countLess(Node* root, TYPE kkey) {
		if (root == nullptr) return 0;
		if (kkey < root->key) return countLess(root->lNode, kkey);

		int leftSize = (root->lNode == nullptr) ? 0 : root->lNode->size;
		return leftSize + 1 + countLess(root->rNode, kkey);
	}
};

int N, shift[50001];

int* solve()
{
	int* ret = new int[N];
	
	Node<int>* fnode = new Node<int>(1);
 	for (int i = 2; i <= N; ++i) {
		Node<int>* node = new Node<int>(i);
		fnode = Node<int>::insert(fnode, node);
	}

	Node<int>* kthNode;
	for (int i = N; i > 0; --i) {
		kthNode = Node<int>::findKth(fnode, i - shift[i - 1]);
		ret[i - 1] = kthNode->key;
		fnode = Node<int>::erase(fnode, kthNode->key);
	}
	
	return ret;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (int n = 0; n < N; ++n)
			scanf("%d", shift + n);
		
		int* ans = solve();
		for (int i = 0; i < N; ++i)
			printf("%d ", ans[i]);
		printf("\n");
		delete ans;
	}
}