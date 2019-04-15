#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
int arr2[21];
int cnt2 = 1;
int idx2 = 0;
int n;
int dp[1000001];
int MOD = 1000000000;


int main() {
	
	
	while (true) {
		if (cnt2 > 1000000)
			break;
		arr2[idx2] = cnt2;
		cnt2 *= 2;
		idx2++;
	}
	scanf("%d", &n);
	for (int i = 0; i <= n; i++) {
		dp[i] = 1;
	}
	for (int i = 1; i < 20; i++) {
		if (arr2[i] > n)
			break;
		for (int j = 0; j <= n; j++) {
			if (arr2[i] + j > n)
				break;
			dp[j + arr2[i]] += dp[j];
			dp[j + arr2[i]] %= MOD;
		}
	}
	printf("%d\n", dp[n]);

}