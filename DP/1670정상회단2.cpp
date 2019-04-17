#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

long long n;
long long MOD = 987654321;
long long dp[10000];
long long fun(int restP) {
	if (restP == 0) 
		return 1;
	if (restP % 2 == 1)
		return 0;
	//남은 친구가 홀수면 모든 친구들이 악수를 하지 못한다.
	long long &reg = dp[restP];
	if (reg != -1)
		return reg;
	reg = 0;
	for (int i = 1; i <= restP; i++) {
		reg += fun(i-2)*fun(restP - i);
		reg %= MOD;
	}//고정 친구 하나가 돌아가면서 다른 친구와 악수를 할 때 
	//교차하지 못한다는 조건에 의하여 2개의 그룹으로 나뉘게 된다.
	//즉 2개의 인원만 달라진 같은 문제가 된다.

	return reg;
}
int main() {
	scanf("%lld", &n);
	memset(dp, - 1, sizeof(dp));
	long long result = 0;
	result = fun(n);
	printf("%lld\n", result);
}