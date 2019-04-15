#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int t;
int n;
int dp[26];

int fun(int idx) {
	if (idx < 0)
		return 0;

	if (idx == 0)
		return 1;
	int &reg = dp[idx];
	if (reg != -1)
		return reg;
	if (idx % 2 == 0)
		reg = 1;
	reg = 0;
	reg += fun(idx - 2) * 4;
	
	reg += fun(idx - 1);

	for (int i = idx / 2 * 2; i >= 4; i-=2) {
		reg += fun(idx - i)*3;
	}
	int tempI;
	if (idx % 2 == 1)
		tempI = idx;
	else
		tempI = idx - 1;
	for (int i = tempI; i >= 3; i -= 2) {
		reg += fun(idx - i)*2;
	}
	return reg;

}
int main() {
	scanf("%d", &t);

	memset(dp, -1, sizeof(dp));
	while (t--) {
		scanf("%d", &n);

		printf("%d\n", fun(n));
	}
}