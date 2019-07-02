#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
int dp[5000001][2];

int t, a, b;

int fun(int curVal, int state) {
	if (curVal > t)
		return -987654321;
	int &reg = dp[curVal][state];
	if (reg != -1)
		return reg;
	if (state == 0) {
		reg = max(fun(curVal / 2, 1), fun(curVal + a, 0));
		reg = max(fun(curVal + b, 0), reg);
		reg = max(reg, curVal);
	}
	else {

		reg = fun(curVal + a, 1);
		reg = max(fun(curVal + b, 1), reg);
		reg = max(reg, curVal);
	}
	return reg;
}
int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d %d %d", &t, &a, &b);
	printf("%d\n", fun(0, 0));
}