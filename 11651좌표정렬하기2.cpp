#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int a, b;
vector<pair<int, int>>arr;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		arr.push_back({ b,a });
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", arr[i].second, arr[i].first);
	}
}