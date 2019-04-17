#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
int dp[52][52];
bool visit[52][52];
int arr[52][52];
int n, m;
string a;
int fun(int curx, int cury) {
	if (curx < 0 || curx >= n || cury >= m || cury < 0)
		return 0;
	if (arr[curx][cury] == -1)
		return 0;
	if (visit[curx][cury])
		return 987654321;
	int &reg = dp[curx][cury];
	if (reg != -1)
		return reg;
	visit[curx][cury] = true;
	reg = fun(curx + arr[curx][cury], cury)+1;
	reg = max(reg, fun(curx, cury + arr[curx][cury])+1);
	reg = max(reg, fun(curx - arr[curx][cury], cury)+1);
	reg = max(reg, fun(curx, cury - arr[curx][cury])+1);

	visit[curx][cury] = false;
	return reg;
}


int main() {
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a;
		for (int j = 0; j < m; j++) {
			if (a[j] != 'H') {
				arr[i][j] = a[j] - '0';
			}
			else {
				arr[i][j] = -1;
			}
		}
	}
	int result = fun(0, 0);
	if (result >= 987654321) {
		cout << "-1\n";
	}
	else {
		cout << result<<"\n";
	}
}
