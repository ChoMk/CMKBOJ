#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int n;
int dp[100001];

int fun(int curN) {
	if (curN == n)
		return 0;
	if (curN > n)
		return 987654321;
	int &reg = dp[curN];
	if (reg != -1)
		return reg;
	reg = 987654321;
	for (int i = 1; i <= 317; i++) {
		reg = min(reg, fun(curN + i * i) + 1);
	}
	return reg;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	printf("%d\n", fun(0)); 
}