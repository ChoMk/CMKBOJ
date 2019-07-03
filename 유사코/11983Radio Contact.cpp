#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>

using namespace std;
long long dp[1002][1002];
int n, m;
vector<pair<long long, long long>> arr1;
vector<pair<long long, long long>> arr2;
string c1;
string c2;
long long sx1, sy1;
long long sx2, sy2;
long long fun(int cur1, int cur2) {
	if (cur1 == n + 1 && cur2 == m + 1)
		return 0;
	if (cur1 == n + 1 || cur2 == m + 1)
		return 100000000000000000;
	long long &reg = dp[cur1][cur2];
	if (reg != -1)
		return reg;
	reg = 100000000000000000;
	long long temp = min(fun(cur1 + 1, cur2), fun(cur1, cur2 + 1));
	temp = min(temp, fun(cur1 + 1, cur2 + 1));
	reg = temp + (arr1[cur1].first - arr2[cur2].first)*(arr1[cur1].first - arr2[cur2].first)
		+ (arr1[cur1].second - arr2[cur2].second)*(arr1[cur1].second - arr2[cur2].second);
	return reg;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	cin >> sx1 >> sy1;
	arr1.push_back({ sx1, sy1 });
	cin >> sx2 >> sy2;
	arr2.push_back({ sx2, sy2 });

	cin >> c1 >> c2;
	for (int i = 0; i < n; i++) {
		if (c1[i] == 'N') {
			sy1++;
		}
		else if (c1[i] == 'E') {
			sx1++;
		}
		else if (c1[i] == 'S') {
			sy1--;
		}
		else {
			sx1--;
		}
		arr1.push_back({ sx1, sy1 });
	}
	for (int i = 0; i < m; i++) {
		if (c2[i] == 'N') {
			sy2++;
		}
		else if (c2[i] == 'E') {
			sx2++;
		}
		else if (c2[i] == 'S') {
			sy2--;
		}
		else {
			sx2--;
		}

		arr2.push_back({ sx2, sy2 });
	}
	cout << fun(0, 0) - (arr1[0].first - arr2[0].first)*(arr1[0].first - arr2[0].first)
		- (arr1[0].second - arr2[0].second)*(arr1[0].second - arr2[0].second) << "\n";
}