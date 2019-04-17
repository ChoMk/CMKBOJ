#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;


long long dp[16][136];
long long a, b;
long long s;
long long arr10[16];
long long minsol = -1;

long long fun(long long prefix, int digits, int sum) {
	if (sum < 0)
		return 0;
	long long minval = prefix;
	long long maxval = prefix + arr10[digits] - 1;
	if (minval > b || maxval < a) return 0;

	if (digits == 0) {
		if (sum > 0)return 0;
		if (minsol == -1)minsol = prefix;
		return 1;
	}
	long long &reg = dp[digits][sum];

	bool dpable = (minval >= a && maxval <= b);
	if (dpable && reg != -1)
		return reg;
	long long temp = 0;
	for (int i = 0; i < 10; i++) {
		temp += fun(prefix + i * arr10[digits - 1], digits - 1, sum - i);
	}
	if (dpable) reg = temp;//�־��� �������� ū ������ ���� �� �ִ�. 0 ~ 10000000000->...->0~10 �� ���Ŀ� dp[1][5]�� for������ ���� ��������
	//dpable ������ �������� �ʴ´�.
	//�� ��츦 Ŀ���ϱ� ���Ͽ� ���� ���� ������ Ʈ���ŷ� ����
	return temp;
}

int main() {
	arr10[0] = 1;
	for (int i = 1; i <= 15; i++) {
		arr10[i] = arr10[i - 1] * 10;
	}
	memset(dp, -1, sizeof(dp));
	scanf("%lld %lld %lld", &a, &b, &s);
	printf("%lld\n", fun(0, 15, s));
	printf("%lld\n", minsol);
}