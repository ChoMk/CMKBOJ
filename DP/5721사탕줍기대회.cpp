#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;

int dp[100101];
int n, m;
int arr[100101];
int arr2[100101];

int fun(int curidx) {
	if (curidx >= m)
		return 0;
	int &reg = dp[curidx];
	if (reg != -1)
		return reg;
	reg = max(fun(curidx + 1), fun(curidx + 2) + arr[curidx]);
	return reg;
}
int fun2(int curidx) {
	if (curidx >= n)
		return 0;
	int &reg = dp[curidx];
	if (reg != -1)
		return reg;
	reg = max(fun2(curidx + 1), fun2(curidx + 2) + arr2[curidx]);
	return reg;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (true) {
		
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[j];
				
				dp[j] = -1;
			}
			arr2[i] = fun(0);
		}
		memset(dp, -1, sizeof(dp));
		cout << fun2(0)<<"\n";
	}

}