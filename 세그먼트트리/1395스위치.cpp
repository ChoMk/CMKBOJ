#include<cstdio>
#include<algorithm>

using namespace std;

int n, q;
int a, b, c;
int bottomStartIDX = 1;
int tree[400001];
int lazy[400001];
void propaggate(int pos, int left, int right) {
	if (lazy[pos] != 0) {
		if (pos < bottomStartIDX) {
			lazy[pos * 2] += lazy[pos];
			lazy[pos * 2] %= 2;
			lazy[pos * 2 + 1] += lazy[pos];
			lazy[pos * 2 + 1] %= 2;
		}
		
		tree[pos] = (right - left + 1) - tree[pos];
		lazy[pos] = 0;
	}
}
void update(int leftBound, int rightBound, int left, int right, int pos) {
	
	propaggate(pos, left, right);

	if (leftBound > right || rightBound < left) {
		return;
	}
	if (leftBound <= left && right <= rightBound) {
		lazy[pos] += 1;
		propaggate(pos, left, right);
		return;
	}
	update(leftBound, rightBound, left, (left + right) / 2, pos * 2);
	update(leftBound, rightBound, (left + right) / 2 + 1, right, pos * 2 + 1);
	tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
}
int searchTree(int leftBound, int rightBound, int left, int right, int pos) {
	propaggate(pos, left, right);
	if (leftBound > right || rightBound < left) {
		return 0;
	}
	if (leftBound <= left && right <= rightBound) {
		return tree[pos];
	}
	return searchTree(leftBound, rightBound, left, (left + right) / 2, pos * 2) +
		searchTree(leftBound, rightBound, (left+right)/2+1, right, pos*2+1);

}

int main() {
	scanf("%d %d", &n, &q);
	while (bottomStartIDX < n) {
		bottomStartIDX *= 2;

	}

	for (int i = 0; i < q; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0) {
			update(b - 1, c - 1, 0, bottomStartIDX-1, 1);
		}
		else {
			printf("%d\n", searchTree(b - 1, c - 1, 0, bottomStartIDX - 1, 1));
		}
	}
}