#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;

string arr[3];

int dp[101][101][101];

int fun(int idx1, int idx2, int idx3) {
	
	if (idx1 == arr[0].size() || idx2 == arr[1].size() || idx3 == arr[2].size())
		return 0;
	
	
	int &reg = dp[idx1][idx2][idx3];
	if (reg != -1)
		return reg;
	reg = 0;
	if (arr[0][idx1] == arr[1][idx2] && arr[1][idx2] == arr[2][idx3]) {
		reg = fun(idx1+1, idx2+1, idx3+1)+1;

	}
	reg = max(reg, fun(idx1 + 1, idx2, idx3));
	reg = max(reg, fun(idx1, idx2+1, idx3));
	reg = max(reg, fun(idx1, idx2, idx3+1));
	


	return reg;

}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> arr[0];
	cin >> arr[1];
	cin >> arr[2];
	printf("%d\n", fun(0, 0, 0));

}