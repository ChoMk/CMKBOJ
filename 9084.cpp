#include<cstdio>
#include<algorithm>
#include<cstring>


using namespace std;
int t;
int n;
int arr[21];
int p;
int dp[30][10001];

int fun(int idx,int sum) {
	if (sum == p && idx == n)
		return 1;
	if (sum > p)
		return 0;
	if (n == idx)
		return 0;

	int &reg = dp[idx][sum];
	
	if (reg != -1)
		return reg;
	
	reg = 0;
	
	int cnt = 0;
	
	while (true) {
		if (cnt*arr[idx] > p)
			break;
		reg += fun(idx+1,cnt*arr[idx] + sum);
		cnt++;
	}
	return reg;
		


}


int main() {
	scanf("%d", &t);
	while (t--) {
		memset(dp, -1, sizeof(dp));
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		scanf("%d", &p);
		int result = fun(0,0);
		printf("%d\n", result);
	}


}