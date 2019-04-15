#include<cstdio>
#include<algorithm>

using namespace std;
int n, m;
long long arr[1000000];
long long tree[5000000];
int a, b, c;
long long sumTree(int left, int right, int start, int end, int pos) {
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right) {
		return tree[pos];
	}
	return sumTree(left, right, start, (start+end)/2, pos*2) + sumTree(left, right, (start+end)/2+1, end, pos*2+1);
}
void changeTree(int idx, long long val, int start, int end, int pos) {
	if (idx<start || idx>end) {
		return;
	}
	tree[pos] += val;
	if (start != end) {
		changeTree(idx, val, start, (start + end) / 2, pos * 2);
		changeTree(idx, val, (start + end) / 2 + 1, end, pos * 2 + 1);
	}
	return;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);

		if (a == 0) {
			if (b > c) {
				swap(b, c);
			}
			printf("%lld\n", sumTree(b - 1, c - 1, 0, n - 1, 1));
		}
		else {
			changeTree(b - 1, c - arr[b - 1], 0, n - 1, 1);
			arr[b - 1] = c;
		}
	}

}