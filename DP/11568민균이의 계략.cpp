#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n;
int arr[1002];
int dp[1002][1002];
int fun(int idx, int preIDX) {
	if (idx == n+1)
		return 0;
	int &reg = dp[idx][preIDX];
	if (reg != -1)
		return reg;
	if (arr[idx] > arr[preIDX]) {
		reg = max(fun(idx + 1, idx) + 1, fun(idx+1, preIDX));
	}
	else {
		reg = fun(idx + 1, preIDX);
	}
	return reg;
}
int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	printf("%d\n",fun(1, 0));

}