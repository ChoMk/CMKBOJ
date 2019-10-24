#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

int t;
long long n;
int dp[101];
int coin[3] = { 1, 10, 25 };
int fun(int price) {
	if (price == 0)
		return 0;
	if (price < 0) {
		return 987654321;
	}
	int &reg = dp[price];
	if (reg != -1)
		return reg;
	reg = 987654321;
	for (int i = 0; i < 3; i++) {
		reg = min(reg, fun(price - coin[i]) + 1);
	}
	return reg;
}

int main() {
	scanf("%d", &t);
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i < 100; i++) {
		fun(i);
	}
	while (t--) {
		int result = 0;
		scanf("%lld", &n);
		while (true) {
			if (n == 0)
				break;
			result += dp[n % 100];
			n /= 100;
		}
		printf("%d\n", result);

	}
}