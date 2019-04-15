#include<cstdio>

using namespace std;
long long arr[1000001];
long long tree[4000004];

int n, m, k;
int a, b;
long long MOD = 1000000007;

long long makeTree(int start, int end, int pos) {
	if (start == end) {
		return tree[pos] = arr[start];
	}

	return tree[pos] = makeTree(start, (start + end) / 2, pos * 2) * makeTree((start + end) / 2 + 1, end, pos * 2 + 1) % MOD;
}

long long mulTree(int left, int right, int start, int end, int pos) {
	if (left>end || right<start) {
		return 1;
	}//범위 밖
	if (left <= start && end <= right) {
		return tree[pos];//범위가 포함
	}
	return (mulTree(left, right, start, (start + end) / 2, pos * 2) * mulTree(left, right, (end + start) / 2 + 1, end, pos * 2 + 1)) % MOD;
	//범위가 겹치는 경우
}//start, end는 재귀 안의 범위...

long long changeTree(int idx, long long changedVal, int start, int end, int pos) {
	if (idx<start || idx>end) {
		return tree[pos];
	}
	if (start == end) {
		return tree[pos] = changedVal;
	}
	
	return tree[pos] = changeTree(idx, changedVal, start, (end + start) / 2, pos * 2)*changeTree(idx, changedVal, (end + start) / 2 + 1, end, pos * 2 + 1)%MOD;
	
}//idx는 변경할 위치, d는 변경할 만큼의 크기, s,e는 긁은 위치, pos는 트리위치



int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	makeTree(0, n - 1, 1);
	for (int i = 0; i < m + k; i++) {
		scanf("%d %d", &a, &b);
		if (a == 1) {
			long long c;
			scanf("%lld", &c);
			changeTree(b - 1, c, 0, n - 1, 1);
			arr[b - 1] = c;
			
			
		}
		else {
			int c;
			scanf("%d", &c);
			printf("%lld\n", mulTree(b - 1, c - 1, 0, n - 1, 1));
		}
	}

}