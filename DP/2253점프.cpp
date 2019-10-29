#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

bool notJumpIDX[10001];
int n;
int m;
int inputPosition;

int dp[10001][223];


int fun(int currentPosition, int currentSpeed) {
	if (currentSpeed == 0)
		return 987654321;
	if (currentPosition == n)
		return 0;
	if (notJumpIDX[currentPosition])
		return 987654321;
	int &reg = dp[currentPosition][currentSpeed];
	if (reg != -1)
		return reg;
	reg = 987654321;
	reg = min(fun(currentPosition + currentSpeed, currentSpeed), fun(currentPosition + (currentSpeed - 1), currentSpeed - 1));
	reg = min(reg, fun(currentPosition + (currentSpeed + 1), currentSpeed + 1));
	reg++;
	return reg;

}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &inputPosition);
		notJumpIDX[inputPosition] = true;
	}
	int result = fun(2, 1) + 1;
	if (result >= 987654321)
		result = -1;
	printf("%d\n", result);

}