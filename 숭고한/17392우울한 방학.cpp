#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

long long arr[1001];
long long dp[1001][1001];
long long n, m;
long long saveCalA[1001];

long long calA(int a) {
	long long result = 0;
	for (int i = 1; i <= a; i++) {
		result += (i*i);
	}
	return result;
}
long long fun(int curIDX, int curN) {
	if (curIDX >= m)
		return 0;
	if (curN >= n) {
		return 987654321;
	}
	long long &reg = dp[curIDX][curN];
	if (reg != -1)
		return reg;
	reg = 987654321;
	for (int i = curIDX; i < m; i++) {
		long long cost;
		if (-(arr[curN] - (i - curIDX)) <= 0) {
			cost = 0;
		}
		else {
			cost = saveCalA[-(arr[curN] - (i - curIDX))];
		}
		reg = min(reg, fun(i + 1, curN + 1) + cost);
	}

	return reg;

}

int main() {
	scanf("%lld %lld", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	for (int i = 0; i <= m; i++) {
		saveCalA[i] = calA(i);
	}
	memset(dp, -1, sizeof(dp));
	long long result = fun(0, 0);
	for (int i = 1; i <= m; i++) {
		result = min(result, fun(i, 0) + saveCalA[i]);
	}
	printf("%lld\n", result);
}