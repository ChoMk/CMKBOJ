#include<cstdio>
#include<algorithm>
using namespace std;
int arr[100001];
int treeMax[400004];
int treeMin[400004];

int n, m;
int a, b;


int makeMaxTree(int start, int end, int pos) {
	if (start == end) {
		return treeMax[pos] = arr[start];
	}

	return treeMax[pos] = max(makeMaxTree(start, (start + end) / 2, pos * 2), makeMaxTree((start + end) / 2 + 1, end, pos * 2 + 1));
}
int makeMinTree(int start, int end, int pos) {
	if (start == end) {
		return treeMin[pos] = arr[start];
	}

	return treeMin[pos] = min(makeMinTree(start, (start + end) / 2, pos * 2), makeMinTree((start + end) / 2 + 1, end, pos * 2 + 1));
}

int searchMaxTree(int left, int right, int start, int end, int pos) {
	if (left>end || right<start) {
		return 0;
	}//범위 밖
	if (left <= start && end <= right) {
		return treeMax[pos];//범위가 포함
	}
	return max(searchMaxTree(left, right, start, (start + end) / 2, pos * 2) , searchMaxTree(left, right, (end + start) / 2 + 1, end, pos * 2 + 1));
	//범위가 겹치는 경우
}
int searchMinTree(int left, int right, int start, int end, int pos) {
	if (left>end || right<start) {
		return 1000000001;
	}//범위 밖
	if (left <= start && end <= right) {
		return treeMin[pos];//범위가 포함
	}
	return min(searchMinTree(left, right, start, (start + end) / 2, pos * 2), searchMinTree(left, right, (end + start) / 2 + 1, end, pos * 2 + 1));
	//범위가 겹치는 경우
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	makeMaxTree(0, n - 1, 1);
	makeMinTree(0, n - 1, 1);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		printf("%d %d\n", searchMinTree(a - 1, b - 1, 0, n - 1, 1), searchMaxTree(a - 1, b - 1, 0, n - 1, 1));
	}
}