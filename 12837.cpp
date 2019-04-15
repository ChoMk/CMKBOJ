#include<cstdio>
#include<algorithm>

long long tree[4000004];
int n, m;
int a, b, c;

void changeTree(int idx, int val,int start, int end ,int pos) {
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

long long sumTree(int left, int right, int start, int end, int pos) {
	if (left > end || right < start) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree[pos];
	}
	return sumTree(left, right, start, (start + end) / 2, pos * 2) + sumTree(left, right, (start + end) / 2 + 1, end, pos * 2 + 1);
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1) {
			changeTree(b-1, c, 0, n - 1, 1);
		}
		else {
			printf("%lld\n", sumTree(b-1, c-1, 0, n - 1, 1));
		}
	}

}