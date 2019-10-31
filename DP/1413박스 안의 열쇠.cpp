#include<algorithm>
#include<cstring>
#include<cstdio>

using namespace std;

long long dp[21][21];
long long gcd(long long a, long long b) { return b ? gcd(b, a%b) : a; }
long long fac[21];
int n, m;

long long fun(int currentN, int currentM) {
	if (currentN == 0)
		return 1;
	if (currentM == 0)
		return 0;
	long long &reg = dp[currentN][currentM];
	if (reg != -1)
		return reg;
	reg = 0;
	for (int i = 1; i <= currentN; i++) {
		reg += fac[currentN - 1] / fac[currentN - i] * fun(currentN - i, currentM - 1);
	}
	return reg;
}
int main() {
	scanf("%d %d", &n, &m);
	memset(dp, -1, sizeof(dp));
	fac[0] = 1;
	for (int i = 1; i < 21; i++) {
		fac[i] = fac[i - 1] * i;
	}
	long long a = fun(n, m);
	long long b = fac[n];
	long long g = gcd(a, b);
	printf("%lld/%lld\n", (a / g), (b / g));
}