#include<cstdio>
#include<algorithm>

using namespace std;

long long arr[500001];
long long tree[2000004];
int n, m;
int a, b, c;

long long makeTree(int start, int end, int pos) {
	if (start == end) {
		return tree[pos] = arr[start];
	}
	return tree[pos] = makeTree(start, (start + end) / 2, pos * 2) + makeTree((end + start) / 2 + 1, end, pos * 2 + 1);
}
void changeTree(int idx, int val, int start, int end, int pos) {
	if (idx<start || idx>end) {
		return;
	}
	tree[pos] += val;

	if (start != end) {
		changeTree(idx, val, start, (start + end) / 2, pos * 2);
		changeTree(idx, val, (start + end) / 2 + 1,end, pos * 2 + 1);
		return;
	}
	return;
}
int fun(int start, int end, int pos, long long val) {
	if (start == end) {
		return end;
	}
	if (val > tree[pos * 2]) {
		return fun((start + end) / 2 + 1, end, pos * 2 + 1, val - tree[pos * 2]);
	}
	else {
		return fun(start, (end + start) / 2, pos * 2, val);
	}
}



int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	makeTree(0, n - 1, 1);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &a);
		long long temp;
		if (a == 1) {
			scanf("%d %d", &b, &c);
			changeTree(b - 1, c, 0, n - 1, 1);
			arr[b - 1] += c;
		}
		else {
			scanf("%lld", &temp);
			printf("%d\n", fun(0, n - 1, 1, temp) + 1);
		}
	}


}