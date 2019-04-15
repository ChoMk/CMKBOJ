#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
int dp[1001][1001][2];
int stateArr[1001][1001];
int h, w, n;
int state;


int main() {
	scanf("%d %d %d", &h, &w, &n);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf("%d", &state);
			stateArr[i][j] = state;
		}
	}
	if (n % 2 == 0) {
		dp[0][0][0] = n / 2;
		dp[0][0][1] = n / 2;
	}
	else {
		dp[0][0][0] = n / 2;
		dp[0][0][1] = n / 2;
		dp[0][0][stateArr[0][0]]++;
	}

	for (int i = 1; i < w; i++) {
		if (dp[0][i - 1][1] % 2 == 0) {
			dp[0][i][0] = dp[0][i - 1][1]/2;
			dp[0][i][1] = dp[0][i - 1][1]/2;
		}
		else {
			dp[0][i][0] = dp[0][i - 1][1] / 2;
			dp[0][i][1] = dp[0][i - 1][1] / 2;
			dp[0][i][stateArr[0][i]]++;
		}
		
	}
	for (int i = 1; i < h; i++) {
		if (dp[i - 1][0][0] % 2 == 0) {
			dp[i][0][0] = dp[i - 1][0][0]/2;
			dp[i][0][1] = dp[i - 1][0][0]/2;

		}
		else {
			dp[i][0][0] = dp[i - 1][0][0]/2;
			dp[i][0][1] = dp[i - 1][0][0]/2;
			dp[i][0][stateArr[i][0]]++;
		}
		
	}


	for (int i = 1; i < h; i++) {
		for (int j = 1; j < w; j++) {
			if ((dp[i - 1][j][0] + dp[i][j - 1][1]) % 2 == 0) {
				dp[i][j][0] = (dp[i - 1][j][0] + dp[i][j - 1][1]) / 2;
				dp[i][j][1] = (dp[i - 1][j][0] + dp[i][j - 1][1]) / 2;

			}
			else {
				dp[i][j][0] = (dp[i - 1][j][0] + dp[i][j - 1][1]) / 2;
				dp[i][j][1] = (dp[i - 1][j][0] + dp[i][j - 1][1]) / 2;
				dp[i][j][stateArr[i][j]]++;
			}
		}
	}
	int x = 0;
	int y = 0;

	while (true) {
		if (x == h || y == w)
			break;
		if ((dp[x][y][0] + dp[x][y][1]) % 2 == 0) {
			if ((stateArr[x][y] + 1) % 2 == 0) {
				x++;
			}
			else {
				y++;
			}
		}
		else {
			if (stateArr[x][y] == 0) {
				x++;
			}
			else {
				y++;
			}
		}
	}

	printf("%d %d\n", x + 1, y + 1);



}