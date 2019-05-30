#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

vector<pair<long long, long long>> arr;
long long dp[100001][2];
int n;
long long x, y;

long long fun(int sidx, int state) {
	if (sidx == n-1)
		return 0;
	long long &reg = dp[sidx][state];
	if (reg != -1)
		return reg;
	reg = 987654321;
	if (state == 0 && sidx+2<=n-1) {
		reg = min(reg, fun(sidx + 2, 1) + abs(arr[sidx].first - arr[sidx + 2].first) + abs(arr[sidx].second - arr[sidx + 2].second));
	}
	reg = min(reg, fun(sidx + 1, state) + abs(arr[sidx].first - arr[sidx + 1].first) + abs(arr[sidx].second - arr[sidx + 1].second));
	return reg;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &x, &y);
		arr.push_back({ x,y });
	}
	printf("%lld\n", fun(0, 0));
}