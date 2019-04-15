#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>
#include<cstring>

using namespace std;

int dp[501][501];
string arr;
int n;
int fun(int left, int right) {
	if (left == n)
		return 0;
	if (left == right)
		return 0;

	int &reg = dp[left][right];
	if (reg != -1)
		return reg;
	reg = fun(left + 1, right);
	if (arr[left] == 'a') {
		for (int i = left + 1; i < right; i++) {
			if(arr[i] == 't')
				reg = max(reg, fun(left+1, i) + fun(i + 1, right)+2);
		}
	}
	else if (arr[left] == 'g') {
		for (int i = left + 1; i < right; i++) {
			if(arr[i] == 'c')
				reg = max(reg, fun(left+1, i) + fun(i + 1, right)+2);
		}
	}
	
	return reg;

	
}
int main() {
	memset(dp, -1, sizeof(dp));
	cin >> arr;
	n = arr.size();
	printf("%d\n", fun(0, n));
}