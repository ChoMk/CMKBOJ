#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;


long long dp[30][30][30];

long long ina;
long long inb;
long long inc;

long long fun(long long a, long long b, long long c) {
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	if (a > 20 || b > 20 || c > 20)
		return fun(20, 20, 20);
	long long &reg = dp[a][b][c];
	if (reg != -1)
		return reg;
	if (a < b && b < c)
		return reg = fun(a, b, c - 1) + fun(a, b - 1, c - 1) - fun(a, b - 1, c);
	return reg = fun(a - 1, b, c) + fun(a - 1, b - 1, c) + fun(a - 1, b, c - 1) - fun(a - 1, b - 1, c - 1);

}

int main() {
	memset(dp, -1, sizeof(dp));
	while (true) {
		scanf("%lld %lld %lld", &ina, &inb, &inc);
		if (ina == -1 && inb == -1 && inc == -1)
			break;
		printf("w(%lld, %lld, %lld) = %lld\n", ina, inb, inc, fun(ina, inb, inc));
	}

}