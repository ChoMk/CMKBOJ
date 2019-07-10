#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int n, k;

int arr[100001];
int dp[100001][21][4];
int result;
char a;
int fun(int curidx, int curk, int state) {
	if (curidx == n)
		return 0;
	int &reg = dp[curidx][curk][state];
	if (reg != -1)
		return reg;
	reg = 0;

	if (state == 0) {//p
		if (arr[curidx] == 0) {//p
			reg = max(fun(curidx + 1, curk, 0), reg);
			if(curk<k)
				reg = max(reg, fun(curidx + 1, curk + 1, 2) + 1);
		}//xx
		else if (arr[curidx] == 1) {//h

			reg = max(fun(curidx + 1, curk, 0)+1, reg);
			
		}//xx
		else {//s

			reg = max(fun(curidx + 1, curk, 0), reg);
			if(curk<k)
				reg = max(fun(curidx + 1, curk + 1, 1)+1, reg);
		}//xx
	}
	else if (state == 1) {//h
		if (arr[curidx] == 0) {//p
			reg = max(fun(curidx + 1, curk, 1), reg);
			if (curk<k)
				reg = max(reg, fun(curidx + 1, curk+1 , 2) + 1);
			
		}//xx
		else if (arr[curidx] == 1) {//h
			reg = max(fun(curidx + 1, curk, 1), reg);
			if (curk<k)
				reg = max(fun(curidx + 1, curk+1, 0) + 1, reg);
			
		}//xx
		else {//s

			reg = max(fun(curidx + 1, curk, 1) + 1, reg);
			
		}//xx
	}
	else {//s
		if (arr[curidx] == 0) {//p
			reg = max(reg, fun(curidx + 1, curk, 2) + 1);
		}//xx
		else if (arr[curidx] == 1) {//h
			reg = max(fun(curidx + 1, curk, 2), reg);
			if (curk<k)
				reg = max(fun(curidx + 1, curk + 1, 0) + 1, reg);

		}//xx
		else {//s

			reg = max(reg, fun(curidx + 1, curk, 2));
			if (curk<k)
				reg = max(fun(curidx + 1, curk + 1, 1) + 1, reg);
		}//xx
	}
	return reg;

}

int main() {
	cin.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == 'P') {
			arr[i] = 0;
		}
		else if (a == 'H') {
			arr[i] = 1;
		}
		else {
			arr[i] = 2;
		}
	}
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < 3; i++) {
		result = max(result, fun(0, 0, i));
	}
	printf("%d\n", result);
}