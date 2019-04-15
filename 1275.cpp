#include<cstdio>
#include<algorithm>

using namespace std;

long long arr[100001];
long long tree[400004];

int n, m;
int a, b, d;
long long c;

long long makeTree(int start, int end, int pos) {
	if (start == end) {
		return tree[pos] = arr[start];
	}
	return tree[pos] = makeTree(start, (end + start) / 2, pos * 2) + makeTree((end + start) /2 +1, end, pos * 2 + 1);
}

void changeTree(int idx, long long val, int start, int end, int pos) {
	if (idx<start || idx>end)
		return;

	tree[pos] += val;
	if (start != end) {
		changeTree(idx, val, start, (start + end) / 2, pos * 2);
		changeTree(idx, val, (end + start) / 2 + 1, end, pos * 2 + 1);
	}
	return;
}
long long sumTree(int left, int right, int start, int end, int pos) {
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[pos];
	return sumTree(left, right, start, (start + end) / 2, pos * 2) + sumTree(left, right, (start + end) / 2 + 1, end, pos * 2 + 1);
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	makeTree(0, n - 1, 1);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %lld %d", &a, &b, &c, &d);
		if (a > b) {
			swap(a, b);
		}
		printf("%lld\n", sumTree(a - 1, b - 1, 0, n - 1, 1));
		changeTree(c - 1, d - arr[c - 1], 0, n-1, 1);
		arr[c - 1] = d;
	}


}