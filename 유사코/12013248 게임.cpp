#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int n;
int arr[300];
int dp[300][300];

int fun(int s, int e) {
	if (s == e)
		return arr[s];
	int &reg = dp[s][e];
	if (reg != -1)
		return reg;
	reg = 0;
	for (int i = s; i < e; i++) {
		int temp1 = fun(s, i);
		int temp2 = fun(i + 1, e);
		if(temp1 == temp2)
			reg = max(reg,temp2+1);
		
	}
	return reg;
}

int main() {
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result = max(result, fun(i, j));
		}
	}
	printf("%d\n", result);
}