#include<cstdio>
#include<algorithm>
#include<cstring>


using namespace std;
int t;
int n;
long long dp[65][10];

long long fun(int idx, int val) {
	long long &reg = dp[idx][val];
	if (reg != -1)
		return reg;
	if (idx == 0)
		return reg = 1;
	reg = 0;
	for (int i = val; i < 10; i++) {
		reg += fun(idx - 1, i);
	}
	return reg;
}

int main() {
	scanf("%d", &t);
	memset(dp, -1, sizeof(dp));
	while (t--) {
		scanf("%d", &n);
		n--;
		long long sum = 0;
		for (int i = 0; i < 10; i++) {
			sum += fun(n, i);
		}
		printf("%lld\n", sum);
	}
}