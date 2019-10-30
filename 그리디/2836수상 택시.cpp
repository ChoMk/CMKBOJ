#include<algorithm>
#include<vector>
#include<cstdio>

using namespace std;
int m;
int n;
long long result;
vector<pair<int, int>> arr;
int a, b;


int main() {
	scanf("%d %d", &m, &n);
	result = n;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		if (a > b) {
			arr.push_back({b,a});
		}
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++) {
		int startIDX = arr[i].first;
		int endIDX = arr[i].second;
		
		for (int j = i + 1; j < arr.size(); j++) {
			int currentIDX = arr[j].first;
			if (startIDX <= currentIDX && currentIDX <= endIDX) {
				endIDX = max(arr[j].second, endIDX);
				i++;
			}
			else {
				break;
			}
		}
		result += 2 * (endIDX - startIDX);
	}
	printf("%lld\n", result);
}