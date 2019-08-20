#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

int dp[1001][201][201];
int n, m;
int arr[1001];

int fun(int curDay, int restM, int preC) {
	if (curDay == n)
		return 0;
	int &reg = dp[curDay][restM][preC];
	if (reg != -1)
		return reg;
	int cost = 0;
	if (preC > arr[curDay])
		cost = (preC - arr[curDay]);
	reg = fun(curDay + 1, restM, arr[curDay]) + cost*cost;

	for (int i = 1; i <= restM; i++) {
		cost = 0;
		if (preC >= arr[curDay] + i)
			cost = (preC - arr[curDay] - i);
		else {
			break;
		}
		reg = min(reg, fun(curDay + 1, restM - i, arr[curDay] + i)+cost*cost);
	}
	return reg;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	printf("%d\n", fun(1, m, arr[0]));
}