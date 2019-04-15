#include<cstdio>
#include<algorithm>
#include<cstring>


using namespace std;

int t;
int n, k;
long long dp[101][101][2];
long long fun(int idx, int cntOne, int preVal) {
	
	if (idx == 0 && cntOne == 0)
		return 1;
	if (idx == 0)
		return 0;
	long long &reg = dp[idx][cntOne][preVal];
	if (reg != -1)
		return reg;
	if (preVal == 0) {
		reg = fun(idx - 1, cntOne, 0) + fun(idx - 1, cntOne, 1);
	}else {
		reg = fun(idx - 1, cntOne - 1, 1) + fun(idx - 1, cntOne, 0);
	}
	return reg;

}


int main() {
	scanf("%d", &t);
	memset(dp, -1, sizeof(dp));
	while (t--) {
		scanf("%d %d", &n, &k);
		printf("%lld\n", fun(n-1, k, 0) + fun(n-1, k, 1));
	}
}