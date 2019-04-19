#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int dp[1001][1001];
int arr[1001][2];
int n;
int m;
int MWflag;
int fun(int curM, int curW) {
	if (MWflag == 0) {
		if (curW == m)
			return 0;
		if (curM == n)
			return 999999999;
	}
	if (MWflag == 1) {
		if (curM == n) {
			return 0;
		}
		if (curW == m)
			return 999999999;
	}
	int &reg = dp[curM][curW];
	if (reg != -1)
		return reg;
	if (MWflag == 0) {
		reg = fun(curM + 1, curW + 1) + abs(arr[curM][0] - arr[curW][1]);
		reg = min(reg, fun(curM + 1, curW));

	}
	else {
		reg = fun(curM + 1, curW + 1) + abs(arr[curM][0] - arr[curW][1]);
		reg = min(reg, fun(curM, curW + 1));

	}
	return reg;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i][0]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &arr[i][1]);
	}
	if (n >= m) {
		MWflag = 0;
	}
	else {
		MWflag = 1;
	}
	printf("%d\n", fun(0, 0));
}