#include<cstdio>
#include<algorithm>

int n;
int a, b, c;

long long tree[4000000];
int endVal = 1000000 - 1;

void changeTree(int idx, int val, int start, int end, int pos) {
	if (idx<start || idx>end) {
		return;
	}
	tree[pos] += val;
	if (start != end) {
		changeTree(idx, val, start, (end + start) / 2, pos * 2);
		changeTree(idx, val, (end + start) / 2 + 1, end, pos * 2 + 1);
	}
}

int searchTree(long long val, int start, int end, int pos) {
	if (start == end) {
		return start;
	}
	if (val > tree[pos * 2]) {
		return searchTree(val-tree[pos*2], (start + end) / 2 + 1, end, pos*2+1);
	}
	else {
		return searchTree(val, start, (start + end) / 2, pos * 2);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (a == 1) {
			long long standard;
			scanf("%lld", &standard);
			int subCandy = searchTree(standard, 0, endVal, 1) + 1;
			printf("%d\n", subCandy);
			changeTree(subCandy-1, -1, 0, endVal, 1);

		}//b순위의 어떤 맛을 꺼내주기
		else {
			scanf("%d %d", &b, &c);
			changeTree(b-1, c, 0, endVal, 1);
			
		}//사탕트리 변경
	}
}