#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
int n;
int arr[10001];
int dp[10001];

int fun(int idx) {
	if (idx == n)
		return 0;
	int &reg = dp[idx];
	if (reg != -1)
		return reg;
	reg = 0;
	int maxScore = 0, minScore = 10000;
	for (int i = idx; i < n; i++) {
		maxScore = max(maxScore, arr[i]);
		minScore = min(minScore, arr[i]);
		reg = max(reg, fun(i+1)+maxScore- minScore);
	}
	return reg;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);

	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", fun(0));
}