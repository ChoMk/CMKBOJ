#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;


int tree[400001];
int n;
vector<int> R;
vector<int> L;

vector<pair<int, int>> temp;
int arr[100001];
int a;
int bottomStart = 1;
int result;

void updateTree(int idx) {
	idx += bottomStart;
	tree[idx] = 1;
	idx /= 2;
	while (idx > 0) {
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
		idx /= 2;
	}
}

int searchTree(int leftBound, int rightBound, int left, int right, int pos) {
	if (leftBound > right || rightBound < left) {
		return 0;
	}
	if (leftBound <= left && right <= rightBound) {
		return tree[pos];
	}
	return searchTree(leftBound, rightBound, left, (left + right) / 2, pos * 2) + searchTree(leftBound, rightBound, (left + right) / 2 + 1, right, pos * 2 + 1);
}


int main() {
	scanf("%d", &n);
	while (bottomStart < n) {
		bottomStart *= 2;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		temp.push_back({ a, i });
	}
	sort(temp.begin(), temp.end());
	for (int i = 0; i < temp.size(); i++) {
		arr[temp[i].second] = i;
	}
	for (int i = 0; i < n; i++) {
		int curVal = arr[i];
		int tempR = searchTree(curVal, n - 1, 0, bottomStart - 1, 1);
		updateTree(curVal);
		L.push_back(tempR);
	}
	memset(tree, 0, sizeof(tree));
	for (int i = n-1; i >=0; i--) {
		int curVal = arr[i];
		int tempR = searchTree(curVal, n - 1, 0, bottomStart - 1, 1);
		updateTree(curVal);
		R.push_back(tempR);
	}
	reverse(R.begin(), R.end());
	for (int i = 0; i < n; i++) {
		if (R[i] * 2 < L[i] || L[i] * 2 < R[i])
			result++;

	}
	printf("%d\n", result);

}