#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

int n;
int arr[10001];
bool visit[10001];
int dp[10001][2];
vector<int> tree[10001];
int a;
int b;

int fun(int curidx, int prestate) {
	if (visit[curidx] == true)
		return 0;
	int &reg = dp[curidx][prestate];
	if (reg != -1)
		return reg;
	reg = 0;
	visit[curidx] = true;
	if (prestate == 0) {
		reg = arr[curidx];
		for (int i = 0; i < tree[curidx].size(); i++) {
			int nextNode = tree[curidx][i];
			reg += fun(nextNode, 1);
		}

	}
	int tempresult = 0;
	for (int i = 0; i < tree[curidx].size(); i++) {
		int nextNode = tree[curidx][i];
		tempresult += fun(nextNode, 0);
	}
	reg = max(reg, tempresult);
	visit[curidx] = false;
	return reg;

}//prestate는 전 노드가 선택되었는지 여부

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n-1; i++) {
		scanf("%d %d", &a, &b);
		a--;
		b--;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	printf("%d\n", fun(0, 0));

}