#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int t = 1;
int n;
int dp[100001][4];
int arr[100001][4];

int fun(int currentlayer, int idx) {
	if (currentlayer == n - 1 && idx == 2)
		return arr[n - 1][idx];
	if (currentlayer == n)
		return 987654321;
	int &reg = dp[currentlayer][idx];
	if (reg != -987654321)
		return reg;

	if (idx == 1) {
		reg = min(fun(currentlayer, 2), fun(currentlayer + 1, 1));
		reg = min(reg, fun(currentlayer + 1, 2));
	}
	else if (idx == 2) {
		reg = min(fun(currentlayer + 1, 1), fun(currentlayer + 1, 2));
		reg = min(reg, fun(currentlayer + 1, 3));
		reg = min(reg, fun(currentlayer, 3));
	}
	else {
		reg = min(fun(currentlayer + 1, 2), fun(currentlayer + 1, 3));
	}
	reg += arr[currentlayer][idx];
	return reg;
}
int main() {
	while (true) {
		scanf("%d", &n);
		if (n == 0)
			break;
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < 100001; i++) {
			for (int j = 0; j < 4; j++) {
				dp[i][j] = -987654321;
			}
		}
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &arr[i][1], &arr[i][2], &arr[i][3]);
		}

		printf("%d. %d\n", t,fun(0, 2));
		t++;
	}
}