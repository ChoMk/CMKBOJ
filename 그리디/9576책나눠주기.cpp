#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

int t;
int a, b;
int n, m;

bool check[1001];

int main() {
	scanf("%d", &t);
	while (t--) {
		memset(check, false, sizeof(check));
		int result = 0;
		vector<pair<int, pair<int, int>>> arr;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &a, &b);
			arr.push_back({ b - a,{ b,a } });
		}
		sort(arr.begin(), arr.end());
		for (int i = 0; i < m; i++) {
			int curidx = i;
			for (int j = arr[curidx].second.second; j <= arr[curidx].second.first; j++) {
				if (check[j] == false) {
					check[j] = true;
					result++;
					break;

				}
			}
		}
		printf("%d\n", result);
	}
}