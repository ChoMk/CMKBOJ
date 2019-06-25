#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int n, q;
vector<int> tree[400001];
int startBottomIDX = 1;
int a, b, c;

void treeUpdate(int idx, int val) {
	idx += startBottomIDX;
	tree[idx].push_back(val);
	while (idx > 1) {
		idx /= 2;
		tree[idx].push_back(val);
		
	}
}
int treeSearch(int boundLeft, int boundRight, int left, int right, int pos, int val) {
	if (boundLeft > right || boundRight < left) {
		return 0;
	}
	if (boundLeft <= left && right <= boundRight) {
		return upper_bound(tree[pos].begin(), tree[pos].end(), val) - tree[pos].begin();
	}
	return treeSearch(boundLeft, boundRight, left, (left + right) / 2, pos * 2, val) +
	treeSearch(boundLeft, boundRight, (right + left) / 2 + 1, right, pos * 2 + 1, val);
	
}

int main() {
	scanf("%d %d", &n, &q);
	while (startBottomIDX < n) {
		startBottomIDX *= 2;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		treeUpdate(i, a);
	}
	for (int i = 1; i < startBottomIDX * 2; i++) {
		sort(tree[i].begin(), tree[i].end());
	}
	for (int i = 0; i < q; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == b) {
			printf("%d\n", tree[startBottomIDX + a - 1][0]);
			continue;
		}
		int leftVal = -1000000001;
		int rightVal = 1000000001;
		int mid;
		while (leftVal <= rightVal) {
			mid = (leftVal + rightVal) / 2;
			int idx = treeSearch(a - 1, b - 1, 0, startBottomIDX - 1, 1, mid);
			
			if (idx >= c) {
				rightVal = mid - 1;
			}
			else {
				leftVal = mid + 1;
			}
		}
		printf("%d\n", leftVal);
	}
}