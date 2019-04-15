#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int n;
int arr[101];
int MAX = 20;
int MIN = 0;
long long dp[101][21];

long long fun(int idx, int val) {
	if (val > MAX || val < MIN)
		return 0;
	long long &reg = dp[idx][val];
	if (reg != -1)
		return reg;
	if (idx == n - 1 && val == arr[n - 1])
		return 1;
	if (idx == n - 1)
		return 0;
	return reg = fun(idx + 1, val + arr[idx]) + fun(idx + 1, val - arr[idx]);
}

int main() {
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	printf("%lld\n", fun(0, 0));
}