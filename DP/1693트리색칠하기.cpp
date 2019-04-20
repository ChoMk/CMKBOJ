#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<int> tree[100001];
int dp[100001][12];
int a, b;
bool visit[100001];
int fun(int curnode, int precolor) {
	
	int &reg = dp[curnode][precolor];
	if (reg != -1) {
		return reg;

	}
	reg = 1000000000;
	visit[curnode] = true;
	for (int j = 1; j < 12; j++) {
		if (precolor == j)
			continue;
		int tempresult = j;
		for (int i = 0; i < tree[curnode].size(); i++) {
			int nextnode = tree[curnode][i];
			if (visit[nextnode])
				continue;
			tempresult += fun(nextnode, j);

		}
		reg = min(reg, tempresult);
	}
	
	visit[curnode] = false;
	return reg;
}
int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 0; i < n-1; i++) {
		scanf("%d %d", &a, &b);
		a--;
		b--;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	printf("%d\n", fun(0, 0));
}