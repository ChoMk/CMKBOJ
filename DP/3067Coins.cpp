#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
int t;
int n;
int m;
int arr[22];
int dp[22][10001];
int fun(int idx, int allM) {
	if (allM == m)
		return 1;
	if (idx == n)
		return 0;
	int &reg = dp[idx][allM];
	if (reg != -1)
		return reg;
	int cnt = 0;
	reg = 0;
	while (true) {
		int nextM = allM + cnt * arr[idx];
		if (nextM> m)
			break;
		reg += fun(idx + 1, nextM);
		cnt++;
		
	}
	return reg;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);

		}
		scanf("%d", &m);
		memset(dp, -1, sizeof(dp));
		printf("%d\n", fun(0, 0));
	}
}