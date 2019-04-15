#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int t;
int n;
int dp[33000][182][4];

int fun(int idx, int num, int cnt) {
	if (idx == n)
		return 1;
	if (cnt == 4)
		return 0;
	if (num == 182)
		return 0;
	if (idx > n)
		return 0;
	int &reg = dp[idx][num][cnt];
	if (reg != -1)
		return reg;
	reg = fun(idx + num * num, num, cnt + 1) + fun(idx, num+1, cnt);
	return reg;
}

int main() {
	while (true) {
		scanf("%d", &n);
		memset(dp, -1, sizeof(dp));

		if (n == 0)
			break;
		printf("%d\n", fun(0, 1, 0));
	}
}