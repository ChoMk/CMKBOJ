#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int T, segt[300000];
vector<pair<int, int>> vt;

int add(int pos, int node, int x, int y) {
	if (pos < x || pos > y) return segt[node];
	if (x == y) return ++segt[node];
	int mid = (x + y) / 2;
	return segt[node] = add(pos, node * 2, x, mid) +
		add(pos, node * 2 + 1, mid + 1, y);
}
int sum(int low, int high, int node, int x, int y) {
	if (high < x || low > y) return 0;
	if (low <= x && y <= high) return segt[node];
	int mid = (x + y) / 2;
	return sum(low, high, node * 2, x, mid) +
		sum(low, high, node * 2 + 1, mid + 1, y);
}
int cmp1(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}
int cmp2(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return a.second > b.second;
	return a.first < b.first;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		int n, nodenum = 1, newy[75000] = { 0 };
		ll ans = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			vt.push_back({ x,y });
		}
		sort(vt.begin(), vt.end(), cmp1);

		for (int i = 0; i < n; i++) {
			if (i > 0 && vt[i].second != vt[i - 1].second) nodenum++;
			newy[i] = nodenum;
		}//nodenum은 y가 몇 번째인지를 의미한다.
		for (int i = 0; i < n; i++) {
			vt[i].second = newy[i];
		}
		sort(vt.begin(), vt.end(), cmp2);
		//x를 오름차순으로 순서 강제화
		for (int i = 0; i < n; i++) {
			ans += sum(vt[i].second, n, 1, 1, n);
			add(vt[i].second, 1, 1, n);
		}//x의 순서를 강제시하고 그 x조건과 y의 번째(nodenum)가 동시에 만족하는 점의 수를 세그먼트로 구해주고 그 점 또한
		//최신화를 시켜주자.
		printf("%lld\n", ans);
		vt.clear();
		fill(segt, segt + 300000, 0);
	}
	return 0;
}