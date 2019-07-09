#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
int n, m;
int dp[1002][1002][3];
int arrn[1002][2];
int arrm[1002][2];

int fun(int curn, int curm, int state) {
	
	if (curn >= n || curm > m)
		return 1000000001;
	if (curn == n-1 && curm == m && state == 0)
		return 0;
	int &reg = dp[curn][curm][state];
	if (reg != -1)
		return reg;
	reg = 1000000001;
	if (state == 0) {
		reg = min(fun(curn + 1, curm, 0) + (arrn[curn][0] - arrn[curn + 1][0])*(arrn[curn][0] - arrn[curn + 1][0]) + (arrn[curn][1] - arrn[curn + 1][1])*(arrn[curn][1] - arrn[curn + 1][1])
			, fun(curn + 1, curm, 1) + (arrn[curn][0] - arrm[curm][0])*(arrn[curn][0] - arrm[curm][0]) + (arrn[curn][1] - arrm[curm][1])*(arrn[curn][1] - arrm[curm][1]));
	}
	else {
		reg = min(fun(curn, curm + 1, 1) + (arrm[curm][0] - arrm[curm + 1][0])*(arrm[curm][0] - arrm[curm + 1][0]) + (arrm[curm][1] - arrm[curm + 1][1])*(arrm[curm][1] - arrm[curm + 1][1]),
			fun(curn, curm + 1, 0) + (arrm[curm][0] - arrn[curn][0])*(arrm[curm][0] - arrn[curn][0]) + (arrm[curm][1] - arrn[curn][1])*(arrm[curm][1] - arrn[curn][1]));
	}
	return reg;
}


int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arrn[i][0], &arrn[i][1]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &arrm[i][0], &arrm[i][1]);
	}
	printf("%d\n", fun(0, 0, 0));
}