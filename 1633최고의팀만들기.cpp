#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>

using namespace std;
int dp[1001][16][16];
int arr[1001][2];
int i;
int fun(int idx,int wc, int bc) {
	if (idx == i) {
		if(wc == 15 && bc == 15)
			return 0;
		return -987654321;
	}
		
	if (wc > 15 || bc > 15)
		return -987654321;
	
	int &reg = dp[idx][wc][bc];
	if (reg != -1) {
		return reg;
	}
	reg = arr[idx][0] + fun(idx + 1, wc + 1, bc);
	reg = max(reg, arr[idx][1] + fun(idx + 1, wc, bc+1));
	reg = max(reg, fun(idx + 1, wc, bc));
	return reg;
}

int main() {
	
	memset(dp, -1, sizeof(dp));
	while(true) {
		if (!(cin>>arr[i][0]>>arr[i][1]))
			break;
		i++;
	}
	int result = fun(0, 0, 0);
	printf("%d\n", result);

}