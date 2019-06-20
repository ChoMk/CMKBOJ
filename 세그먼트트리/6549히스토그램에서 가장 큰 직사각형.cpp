#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
int n;
long long tree[400000];
long long arr[100001];
int startBottomIDX = 1;

void constructTree() {
	for (int i = startBottomIDX - 1; i > 0; i--) {
		if (tree[i * 2] == -1 || tree[i * 2 + 1] == -1) {
			tree[i] = max(tree[i * 2], tree[i * 2 + 1] );
			continue;
		}
		if (arr[tree[i * 2]] < arr[tree[i * 2 + 1]]) {
			tree[i] = tree[i * 2];
		}
		else {
			tree[i] = tree[i * 2 + 1];
		}
	}
}
int searchSegIDX(int boundLeft, int boundRight, int left, int right, int pos) {
	if (boundLeft > right || boundRight < left)
		return -1;
	if (boundLeft <= left && right <= boundRight) {
		return tree[pos];
	}
	int leftIDX = searchSegIDX(boundLeft, boundRight, left, (right + left) / 2, pos * 2);
	int rightIDX = searchSegIDX(boundLeft, boundRight, (right + left) / 2 + 1, right, pos * 2 + 1);
	if (leftIDX == -1 || rightIDX == -1) {
		return max(leftIDX, rightIDX);
	}
	if (arr[leftIDX] < arr[rightIDX]) {
		return leftIDX;
	}
	return rightIDX;
}
long long sol(int left, int right) {
	int minIDX = searchSegIDX(left, right, 0, startBottomIDX - 1, 1);

	long long result = (right - left + 1)*arr[minIDX];
	if (left <= minIDX - 1) {
		result = max(result, sol(left, minIDX - 1));
	}
	if (minIDX + 1 <= right) {
		result = max(result, sol(minIDX + 1, right));
	}
	return result;

}
int main() {
	while (true) {
		scanf("%d", &n);
		if (n == 0)
			return 0;
		memset(tree, 0, sizeof(tree));
		memset(arr, 0, sizeof(arr));
		startBottomIDX = 1;
		while (startBottomIDX < n) {
			startBottomIDX *= 2;
		}
		for (int i = 0; i < n; i++) {
			scanf("%lld", &arr[i]);
			tree[startBottomIDX + i] = i;

		}
		for (int i = startBottomIDX+n; i < startBottomIDX * 2; i++) {
			tree[i] = -1;
		}
		constructTree();
		
		printf("%lld\n", sol(0, n-1));
	}
	

	
	
}