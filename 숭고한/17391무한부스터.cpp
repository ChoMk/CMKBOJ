#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int dp[301][301];
bool visit[301][301];
int n, m;
int arr[301][301];
int fun(int curx, int cury) {
	if (curx >= n || cury >= m) {
		return 987654321;
	}
	if (curx == n - 1 && cury == m - 1)
		return 0;
	if (visit[curx][cury]) {
		return 987654321;
	}
	int &reg = dp[curx][cury];
	if (reg != -1)
		return reg;
	visit[curx][cury] = true;
	reg = 987654321;
	for (int i = 1; i <= arr[curx][cury]; i++) {
		reg = min(reg, fun(curx + i, cury) + 1);
		reg = min(reg, fun(curx, cury + i) + 1);
	}

	visit[curx][cury] = false;
	return reg;
}
int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	printf("%d\n", fun(0, 0));
}