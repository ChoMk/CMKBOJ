#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;


int dp[300001];
int n;
int s;
pair<int, int> paint[300001];
int height[300001];
int a, b;

int fun(int idx) {
	if (idx == n)
		return 0;
	
	int &reg = dp[idx];
	if (reg != -1)
		return reg;	

	reg = max(reg, fun(idx + 1));
	int pos = lower_bound(height, height + n, paint[idx].first + s) - height;
	reg = max(reg, fun(pos) + paint[idx].second);
	return reg;
}


int main() {
	scanf("%d %d", &n, &s);
	memset(dp, -1, sizeof(dp));
	
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &paint[i].first, &paint[i].second);
		height[i] = paint[i].first;
	}

	sort(paint, paint + n);
	sort(height, height + n);

	printf("%d\n", fun(0));
}