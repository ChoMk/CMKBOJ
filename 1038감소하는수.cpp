#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int dp[10][10];
int n;
int sum;

int increaseFun(int idx, int val) {
	int &reg = dp[idx][val];
	if (reg != -1)return reg;
	if (idx == 0)return reg = 1;
	reg = 0;
	for (int i = 0; i <= val - 1; i++) {
		reg += increaseFun(idx - 1, i);
	}
	return reg;
}
void decreaseFun(int idx, int val, int gap) {
	if (idx == 0) {
		printf("%d", val);
		return;
	}
	for (int i = val - 1; i >= 0; i--) {
		if (dp[idx - 1][i] < gap)gap -= dp[idx - 1][i];
		else {
			printf("%d", val);
			decreaseFun(idx - 1, i, gap);
			return;
		}
	}
}



int main() {
	scanf("%d", &n);
	
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			increaseFun(i, j);
			sum += dp[i][j];
			if (n < sum) {
				decreaseFun(i, j, sum - n);
				printf("\n");
				return 0;
			}
		}
	}
	printf("-1\n");
	return 0;
}