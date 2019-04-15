#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int t;
int n;
int arr[101][2];
long long dp[101][10001];
long long fun(int idx, int cost) {
	if (cost == 0)
		return 1;
	if (idx == n || cost<0)
		return 0;
	long long &reg = dp[idx][cost];
	if (reg != -1)
		return reg;
	reg = 0;
	for (int i = 0; i <= arr[idx][1]; i++) {
		reg += fun(idx + 1, cost - arr[idx][0] * i);
	}
	return reg;
}


int main() {
	scanf("%d", &t);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", fun(0, t));

}