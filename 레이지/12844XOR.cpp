#include<cstdio>
#include<algorithm>

using namespace std;

int n;
int tree[2000001];
int lazy[2000001];
int q;
int bottomStartIDX = 1;

void constructTree() {
	for (int i = bottomStartIDX - 1; i > 0; i--) {
		tree[i] = tree[i * 2] ^ tree[i * 2 + 1];
	}
}
void propaggate(int left, int right, int pos) {
	if (lazy[pos] != 0) {
		if (pos < bottomStartIDX) {
			lazy[pos * 2] ^= lazy[pos];
			lazy[pos * 2 + 1] ^= lazy[pos];
		}
		else {
			tree[pos] ^= lazy[pos];

		}
		lazy[pos] = 0;
	}
}
void updateTree(int leftBound, int rightBound, int left, int right, int pos, int val) {
	propaggate(left, right, pos);
	if (leftBound > right || rightBound < left) {
		return;
	}
	if (leftBound <= left && right <= rightBound) {
		lazy[pos] = val;
		propaggate(left, right, pos);
		return;
	}
	updateTree(leftBound, rightBound, left, (left + right) / 2, pos * 2, val);
	updateTree(leftBound, rightBound, (left + right) / 2 + 1, right, pos * 2 + 1, val);
	tree[pos] = tree[pos * 2] ^ tree[pos * 2 + 1];
}
int searchTree(int leftBound, int rightBound, int left, int right, int pos) {
	propaggate(left, right, pos);
	if (leftBound > right || rightBound < left)
		return 0;
	if (leftBound <= left && right <= rightBound)
		return tree[pos];
	return searchTree(leftBound, rightBound, left, (left + right) / 2, pos * 2) ^ searchTree(leftBound, rightBound, (left + right) / 2 + 1, right, pos * 2 + 1);
}

int main() {
	scanf("%d", &n);
	while (bottomStartIDX < n)
		bottomStartIDX *= 2;
	for (int i = 0; i < n; i++) {
		scanf("%d", &tree[bottomStartIDX + i]);
	}
	constructTree();
	scanf("%d", &q);
	int t, a, b, c;
	for (int i = 0; i < q; i++) {
		scanf("%d", &t);
		if (t == 1) {
			scanf("%d %d %d", &a, &b, &c);
			updateTree(a, b, 0, bottomStartIDX - 1, 1, c);
		}
		else {
			scanf("%d %d", &a, &b);
			printf("%d\n", searchTree(a, b, 0, bottomStartIDX - 1, 1));
		}
	}
}