#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

long long dp[1000001];
int n;

long long fun(int restP) {
	long long &reg = dp[restP];
	if (reg != -1)
		return reg;
	if (restP <= 1)
		return reg = 0;
	if (restP == 2)
		return reg = 1;
	reg = (fun(restP - 1) +fun(restP-2))*(restP - 1) % 1000000000;

	return reg;
}


int main() {
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", fun(n));
	
}