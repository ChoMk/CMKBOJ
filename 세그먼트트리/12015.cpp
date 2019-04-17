#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int n;
pair<int, int>arr[1000001];
int a;
int result;
int tree[4000004];

int searchMax(int left, int right, int start, int end, int pos) {
	if (left > end || right < start) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree[pos];
	}
	return max(searchMax(left, right, start, (start + end) / 2, pos * 2), searchMax(left, right, (start + end) / 2 + 1, end, pos * 2 + 1));
}

int changeTree(int idx, int val, int start, int end, int pos) {

	if (idx<start || idx>end)
		return tree[pos];
	if (start == end) {
		return tree[pos] = val;
		
	}
	return tree[pos] = max(	changeTree(idx, val, start, (start + end) / 2, pos * 2), changeTree(idx, val,(start + end) / 2 + 1, end, pos * 2 + 1));
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		arr[i] = { a,i };
	}
	sort(arr, arr+n, [](const pair<int, int> &p, const pair<int, int> &q) {
		if (p.first != q.first) return p.first < q.first;
		return p.second > q.second;
	});
	for (int i = 0; i < n; i++) {
		int temp = searchMax(0, arr[i].second, 0, n-1, 1) + 1;
		result = max(result, temp);
		changeTree(arr[i].second, temp, 0, n - 1, 1);
	}
	printf("%d\n", result);

}