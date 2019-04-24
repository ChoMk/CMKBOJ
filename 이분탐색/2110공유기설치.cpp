#include<cstdio>
#include<algorithm>

using namespace std;

int n;
int c;
int arr[200000];
int maxE;

bool fun(int curidx, int remain) {
	if (remain == 0)
		return true;
	for (int i = curidx + 1; i < n; i++) {
		if (arr[i] - arr[curidx] >= maxE)
			return fun(i, remain - 1);
	}
	return false;
}

int main() {
	scanf("%d %d", &n, &c);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	int upper = arr[n - 1] + 1;
	int lower = 1;
	while (lower + 1 < upper) {
		maxE = (upper + lower) / 2;
		if (fun(0, c - 1)) lower = maxE;
		else upper = maxE;
	}
	printf("%d\n", lower);
}