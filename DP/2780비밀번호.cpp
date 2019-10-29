#include<algorithm>
#include<cstring>
#include<cstdio>

using namespace std;

bool numberTable[4][3] = { {true,true,true},{true,true,true},{true,true,true},{true, false, false} };
long long dp[1001][4][4];
int t;
int n;
int cont[4][2] = { {0,1},{1,0}, {0,-1},{-1, 0} };


long long fun(int currentL, int currentX, int currentY) {
	if (currentX < 0 || currentY < 0 || currentY >= 3 || currentX >= 4)
		return 0;
	if (!numberTable[currentX][currentY])
		return 0;
	if (currentL == 0)
		return 1;
	long long &reg = dp[currentL][currentX][currentY];
	if (reg != -1)
		return reg;
	reg = 0;
	for (int i = 0; i < 4; i++) {
		int nextX = currentX + cont[i][0];
		int nextY = currentY + cont[i][1];
		reg += fun(currentL - 1, nextX, nextY);
		reg %= 1234567;
	}
	return reg;

}

int main() {
	scanf("%d", &t);
	memset(dp, -1, sizeof(dp));

	while (t--) {
		
		scanf("%d", &n);
		long long result = fun(n-1, 3, 0);
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				result += fun(n-1, i, j);
				result %= 1234567;
			}
		}
		printf("%lld\n", result);
	}
}