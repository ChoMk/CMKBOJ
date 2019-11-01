#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

int n;
int dp[1001][1001];
vector<pair<pair<int, int>, int>>arr;
bool visit[101];
int a, b, c;
int fun(int currentSTR, int currentINT) {
	int &reg = dp[currentSTR][currentINT];
	if (reg != -1)
		return reg;
	reg = 0;
	vector<int> canClearQ;
	int point = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i].first.first <= currentSTR || arr[i].first.second <= currentINT) {
			if (!visit[i]) {
				visit[i] = true;
				point += arr[i].second;
				canClearQ.push_back(i);

			}
			cnt++;
		}
	}
	reg = cnt;
	for (int i = 0; i <= point; i++) {
		int nextVal = fun(min(1000, currentSTR + i), min(1000,currentINT + (point - i)));
		reg = max(reg, nextVal);
	}
	for (int i = 0; i < canClearQ.size(); i++) {
		visit[canClearQ[i]] = false;
	}
	return reg;
}
int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		arr.push_back({ {a,b},c });
	}
	printf("%d\n", fun(1, 1));
}