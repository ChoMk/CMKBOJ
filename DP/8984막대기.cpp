#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

long long top_dp[100001];
long long down_dp[100001];

vector<pair<int, int>> arr;
vector<int> arrT;
vector<int> arrD;

int a, b;
int n, l;

int main() {
	scanf("%d %d", &n, &l);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		arr.push_back({ a,b });
		arrT.push_back(a);
		arrD.push_back(b);
	}
	sort(arr.begin(), arr.end());
	sort(arrT.begin(), arrT.end());
	sort(arrD.begin(), arrD.end());

	arrT.erase(unique(arrT.begin(), arrT.end()), arrT.end());
	arrD.erase(unique(arrD.begin(), arrD.end()), arrD.end());
	//중복 제거... 좌표점만 남음

	long long result = 0;

	for (int i = 0; i < n; i++) {
		int tidx = lower_bound(arrT.begin(), arrT.end(), arr[i].first) - arrT.begin();
		int didx = lower_bound(arrD.begin(), arrD.end(), arr[i].second) - arrD.begin();
		int len = l + (abs(arr[i].first - arr[i].second));
		long long tempT = top_dp[tidx];
		long long tempD = down_dp[didx];
		top_dp[tidx] = max(tempT, tempD + len);
		down_dp[didx] = max(tempD, tempT + len);
		result = max(result, max(top_dp[tidx], down_dp[didx]));
	}
	printf("%lld\n", result);
}