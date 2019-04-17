#include<cstdio>
#include<algorithm>

using namespace std;

int n;
int h[100000];
int arr[100000];
int tree[400000];
int result[100000];

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
		scanf("%d", &h[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		changeTree(i, 1, 0, n-1, 1);
	}

	for (int i = 0; i <n; i++) {
		result[searchTree(arr[i] + 1, 0, n - 1, 1)] = h[i];
	}
	for (int i = 0; i <n; i++) {
		printf("%d\n", result[i]);
	}

}