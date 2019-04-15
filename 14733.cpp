#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<pair<int, int>> x;
vector<pair<int, int>> y;

vector<pair<int, int>> resultX;
vector<pair<int, int>> resultY;
int a, b, c, d;

bool visit[3001];

int main() {
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		int sw = 0;
		for (int i = 0; i < x.size(); i++) {
			int presentXs = x[i].first;
			int presentXe = x[i].second;
			if (presentXs <= a && c <= presentXe) {
				sw = 1;
				break;
			}
			else if ((c <= presentXe && c >= presentXs) || (a <= presentXe && a >= presentXs)) {
				presentXe = max(c, presentXe);
				presentXs = min(a, presentXs);
				x[i].first = presentXs;
				x[i].second = presentXe;
				sw = 1;
				break;
			}


		}
		if (sw == 0)
			x.push_back({ a,c });
		sw = 0;
		for (int i = 0; i < y.size(); i++) {
			int presentYs = y[i].first;
			int presentYe = y[i].second;
			if (presentYs <= b && d <= presentYe) {
				sw = 1;
				break;
			}
			else if ((d <= presentYe && d >= presentYs) || (b <= presentYe && b >= presentYs)) {
				presentYe = max(d, presentYe);
				presentYs = min(b, presentYs);
				y[i].first = presentYs;
				y[i].second = presentYe;
				sw = 1;
				break;
			}

		}
		if (sw == 0)
			y.push_back({ b,d });
	}

	for (int i = 0; i < x.size(); i++) {
		for (int j = i + 1; j < x.size(); j++) {

		}
	}

}