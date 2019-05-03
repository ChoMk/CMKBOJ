#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int arr[30001];
int n;
int result;
int preJ;
int dp[30001][3];

int fun(int idx, int prestate) {
	if (idx == n)
		return 0;
	int &reg = dp[idx][prestate];
	if (reg != -1)
		return reg;
	if (prestate == 1) {
		if (arr[idx] == 1) {
			reg = min(fun(idx + 1, 1), fun(idx + 1, 2) + 1);
		}
		else {
			reg = min(fun(idx + 1, 1) + 1, fun(idx + 1, 2));
		}
	}
	else {
		if (arr[idx] == 1) {
			reg = fun(idx + 1, 2) + 1;
		}
		else {
			reg = fun(idx + 1, 2);
		}
	}
	return reg;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	printf("%d\n", fun(0, 1));
}