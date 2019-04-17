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
	//���� ģ���� Ȧ���� ��� ģ������ �Ǽ��� ���� ���Ѵ�.
	long long &reg = dp[restP];
	if (reg != -1)
		return reg;
	reg = 0;
	for (int i = 1; i <= restP; i++) {
		reg += fun(i-2)*fun(restP - i);
		reg %= MOD;
	}//���� ģ�� �ϳ��� ���ư��鼭 �ٸ� ģ���� �Ǽ��� �� �� 
	//�������� ���Ѵٴ� ���ǿ� ���Ͽ� 2���� �׷����� ������ �ȴ�.
	//�� 2���� �ο��� �޶��� ���� ������ �ȴ�.

	return reg;
}
int main() {
	scanf("%lld", &n);
	memset(dp, - 1, sizeof(dp));
	long long result = 0;
	result = fun(n);
	printf("%lld\n", result);
}