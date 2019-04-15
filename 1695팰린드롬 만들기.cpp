#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int dp[5001][5001];
int arr[5001];
int n;

int fun(int left, int right) {
	if (left > right)
		return 0;
	int &reg = dp[left][right];
	if (reg != -1)
		return reg;
	if (arr[left] == arr[right]) {
		reg = fun(left + 1, right - 1);
	}
	else {
		reg = min(fun(left + 1, right) + 1, fun(left, right - 1) + 1);
	}
	return reg;
}

int main() {
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	printf("%d\n", fun(0, n - 1));
}