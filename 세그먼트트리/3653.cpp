#include<cstdio>
#include<algorithm>
#include<cstring>



using namespace std;


int tree[800008];
int arr[200002];
int t;
int n, m;
int v;
int update(int idx, int val, int start, int end, int pos) {
	if (end < idx || idx < start) {
		return tree[pos];
	}
	if (start == end) {
		return tree[pos] = val;
	}
	return tree[pos] = update(idx, val, start, (start + end) / 2, pos * 2) + update(idx, val, (start + end) / 2 + 1, end, pos * 2 + 1);
}

int sumTree(int left, int right, int start, int end, int pos) {
	if (end < left || right < start) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree[pos];
	}
	return sumTree(left, right, start, (start + end) / 2, pos * 2) + sumTree(left, right, (start + end) / 2 + 1, end, pos * 2 + 1);
}


int main() {
	scanf("%d", &t);

	while (t--) {
		memset(arr, 0, sizeof(arr));
		memset(tree, 0, sizeof(tree));
		scanf("%d %d", &n, &m);
		for (int i = m; i < n + m; i++) {
			update(i, 1, 0, n+m - 1, 1);//
			arr[i - m] = i;//dvd가 실제로 어느 위치에 있는지 저장
		}
		int idx = m-1;
		for (int i = 0; i < m; i++) {
			scanf("%d", &v);
			printf("%d ", sumTree(0, arr[v-1]-1, 0, n + m - 1, 1));
			update(arr[v-1], 0, 0, n + m - 1, 1);
			arr[v-1] = idx--;
			update(arr[v-1], 1, 0, n + m - 1, 1);
		}
		printf("\n");

	}
}