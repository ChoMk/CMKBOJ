#include<algorithm>
#include<cstdio>

using namespace std;
int n, q;
int tree[1200000];
int arr[300001];
int startIDX = 1;

void constructTree() {
	for (int i = startIDX - 1; i > 0; i--) {
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}
}

int searchTree(int leftBound, int rightBound, int left, int right, int pos) {
	if (leftBound > right || rightBound < left) {
		return 0;
	}
	if (leftBound <= left && right <= rightBound) {
		return tree[pos];
	}
	return searchTree(leftBound, rightBound, left, (left + right) / 2, pos * 2) +
		searchTree(leftBound, rightBound, (left + right) / 2 + 1, right, pos * 2 + 1);
}

int main() {
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	while (startIDX < n) {
		startIDX *= 2;
	}

	for (int i = 0; i < n; i++) {
		tree[i + startIDX] = arr[i];
	}
	constructTree();
	int a, b;
	for (int i = 0; i < q; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", searchTree(a - 1, b - 1, 0, startIDX - 1, 1));
	}
}