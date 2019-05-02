#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int dp[301][301];
int n, m;
int fun(int x, int y) {
	if (x == 1 && y == 1) {
		return 0;
	}
	int &reg = dp[x][y];
	if (reg != -1) {
		return reg;
	}
	reg = 987654321;
	for (int i = 1; i < x; i++) {
		reg = min(fun(i, y) + fun(x - i, y)+1, reg);
	}
	for (int i = 1; i < y; i++) {
		reg = min(fun(x, i) + fun(x, y-i)+1, reg);
	}
	return reg;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &n, &m);
	printf("%d\n", fun(n, m));
}