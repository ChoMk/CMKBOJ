#include<cstdio>
#include<algorithm>

using namespace std;
int n, m;
int tree[400000];
int startBottomIDX = 1;
int a, b;
void constructTree() {
	for (int i = startBottomIDX - 1; i > 0; i--) {
		tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
	}
}
int searchMinVal(int boundLeft, int boundRight, int left, int right, int pos) {
	if (boundLeft > right || boundRight < left) {
		return 987654321;
	}
	if (boundLeft <= left && right <= boundRight) {
		return tree[pos];
	}
	return min(searchMinVal(boundLeft, boundRight, left, (right + left) / 2, pos * 2), searchMinVal(boundLeft, boundRight, (left + right) / 2 + 1, right, pos * 2 + 1));
}
int main() {
	scanf("%d %d", &n, &m);
	while (startBottomIDX < n) {
		startBottomIDX *= 2;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &tree[startBottomIDX + i]);
	}
	for (int i = n + startBottomIDX; i < startBottomIDX * 2; i++) {
		tree[i] = 987654321;
	}
	constructTree();
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", searchMinVal(a - 1, b - 1, 0, startBottomIDX - 1, 1));
	}
}