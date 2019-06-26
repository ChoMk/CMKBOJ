#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int tree[2000001];
int result;
int n;
int a;
int bottomStartIDX = 1;
int INF = 987654321;

void constructTree() {
	for (int i = 1; i < bottomStartIDX * 2; i++) {
		tree[i] = INF;
	}
	return;
}
void updateTree(int idx, int val) {
	idx += bottomStartIDX;
	tree[idx] = val;
	while (idx > 1) {
		idx /= 2;
		tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
	}

}
int minTree(int leftBound, int rightBound, int left, int right, int pos) {
	if (leftBound > right || rightBound < left)
		return INF;
	if (leftBound <= left && right <= rightBound)
		return tree[pos];
	return min(minTree(leftBound, rightBound, left, (left + right) / 2, pos * 2),
		minTree(leftBound, rightBound, (left + right) / 2 + 1, right, pos * 2 + 1));
}
int main() {
	scanf("%d", &n);
	vector<vector<int>> arr(n, vector<int>(3));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a);
			arr[a - 1][i] = j;//등수 저장
		}
	}
	while (bottomStartIDX < n) {
		bottomStartIDX *= 2;
	}
	constructTree();
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++) {
		if (minTree(0, arr[i][2],0, bottomStartIDX-1, 1) > arr[i][1])result++;
		updateTree(arr[i][2], arr[i][1]);
	}
	printf("%d\n", result);
}