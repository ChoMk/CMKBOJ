#include<algorithm>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include<queue>

using namespace std;

int n;
int sx, sy;
int ex, ey;
map<int, vector<pair<int, int>>> arrX;
map<int, vector<pair<int, int>>> arrY;
vector<pair<int, int>> arr;
int a, b;
bool visit[100002];
int dp[100002][3];
int fun(int curNode, int state) {
	if (curNode == n+1)
		return 0;
	if (visit[curNode])
		return 1000000000;
	int &reg = dp[curNode][state];
	if (reg != -1)
		return reg;

	reg = 1000000000;

	visit[curNode] = true;
	int curx = arr[curNode].first;
	int cury = arr[curNode].second;
	if (state == 0) {
		for (int i = 0; i < arrX[curx].size(); i++) {
			reg = min(reg, fun(arrX[curx][i].second, 1) + 1);
		}
	}
	else {
		for (int i = 0; i < arrY[cury].size(); i++) {
			reg = min(reg, fun(arrY[cury][i].second, 0) + 1);
		}
	}
	visit[curNode] = false;
	return reg;
}

int main() {
	memset(dp, -1, sizeof(dp));
	memset(visit, false, sizeof(visit));
	scanf("%d", &n);
	scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
	arrX[sx].push_back({ sy, 0 });
	arrY[sy].push_back({ sx, 0 });
	arr.push_back({ sx, sy });
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &a, &b);
		arrX[a].push_back({ b, i});
		arrY[b].push_back({ a, i});
		arr.push_back({ a,b });
	}
	arrX[ex].push_back({ ey, n +1});
	arrY[ey].push_back({ ex, n +1});
	arr.push_back({ ex, ey });
	int R = min(fun(0, 0), fun(0, 1));
	if (R >= 1000000000)
		R = -1;
	printf("%d\n", R);
}