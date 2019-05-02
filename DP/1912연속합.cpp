#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int dp[100001];
int arr[100001];
int n;
int fun(int idx) {
	if (idx == -1)
		return 0;
	int &reg = dp[idx];
	if (reg != -1)
		return reg;
	int temp = fun(idx - 1) + arr[idx];
	if (arr[idx] > temp) {
		reg = arr[idx];
	}
	else {
		reg = temp;
	}
	return reg;

}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	fun(n - 1);

	int result = dp[0];
	for (int i = 1; i < n; i++) {
		result = max(result, dp[i]);
	}
	printf("%d\n", result);
	
}