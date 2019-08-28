	#include<algorithm>
	#include<cstring>
	#include<cstdio>

	using namespace std;
	int n, k;
	long long dp[10001];
	int tree[40001];
	int arr[10001];
	long long fun(int curIDX) {
		if (curIDX == n)
			return 0;
		if (curIDX > n)
			return -98765432111111;
		long long &reg = dp[curIDX];
		if (reg != -1)
			return reg;
		reg = -98765432111111;
		long long curMAX = arr[curIDX];
		for (int i = 0; i < k; i++) {
			curMAX = max(curMAX, (long long)arr[curIDX + i]);
			reg = max(reg, fun(curIDX + i + 1) + curMAX * (i + 1));
		}
		return reg;
	}

	int main() {
		memset(dp, -1, sizeof(dp));
		scanf("%d %d", &n, &k);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		printf("%lld\n", fun(0));
	}
