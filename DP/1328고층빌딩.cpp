#include<cstdio>
#include<cstring>
int n;
int l;
int r;
long long dp[101][101][101];
long long mod = 1000000007LL;

long long fun(int count, int left, int right)
{
	if (count == n && left == l && right == r)
		return 1;
	if (count == n)
		return 0;
	long long &reg = dp[count][left][right];
	if (reg != -1)
		return reg;
	reg = (fun(count + 1, left + 1, right) + fun(count + 1, left, right + 1)) % mod + fun(count + 1, left, right)*(count-1);
	reg %= mod;
	return reg;
}


int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d %d %d", &n, &l, &r);
	printf("%lld\n", fun(1, 1, 1));


}