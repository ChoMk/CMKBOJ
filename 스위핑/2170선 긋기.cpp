#include <iostream>
#include <algorithm>
#include <vector>
#define END 1000000000
using namespace std;
int N, lp, rp, ans;

vector<pair<int, int>> vt;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		vt.push_back({ a,b });
	}
	sort(vt.begin(), vt.end());

	//lp = rp = -END;
	lp = vt[0].first;
	rp = vt[0].second;

	for (int i = 1; i < N; i++) {
		if (rp < vt[i].first) {
			ans += rp - lp;
			lp = vt[i].first;
			rp = vt[i].second;
		}//벌어지는 경우 갱신
		else rp = max(rp, vt[i].second);// 아닌경우 오른쪽을 늘려주자
	}
	ans += rp - lp;//늘려주다가 마지막 왼쪽에서 오른쪽 빼서 거리 구해주기
	printf("%d\n", ans);
	return 0;
}