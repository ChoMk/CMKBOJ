#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int n;
int tree[400004];
int arr[100000];
int result[100000];
int temp;
void changeTree(int idx, int val, int start, int end, int pos) {
	if (idx<start || idx>end) {
		return;
	}
	tree[pos] += val;
	if (start != end) {
		changeTree(idx, val, start, (start + end) / 2, pos * 2);
		changeTree(idx, val, (start + end) / 2 + 1, end, pos * 2 + 1);
	}
}

int searchTree(int val, int start, int end, int pos) {
	tree[pos]--;
	if (start == end) {
		return start;
	}
	if (val > tree[pos * 2]) {
		return searchTree(val - tree[pos * 2], (start + end) / 2 + 1, end, pos * 2 + 1);
	}
	else {
		return searchTree(val, start, (end + start) / 2, pos * 2);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		changeTree(i, 1, 0, n - 1, 1);
	}
	for (int i = n-1; i > -1; i--) {
		result[searchTree(arr[i]+1, 0,n-1,1)] = i + 1;
	}
	for (int i = n-1; i > -1; i--) {
		printf("%d ", result[i]);
	}
	printf("\n");
}