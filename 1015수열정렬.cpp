#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

vector<pair<int, int>> arr;
int n;
int a;
vector<pair<int, int>> result;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		arr.push_back({ a, i });
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++) {
		result.push_back({ arr[i].second,i });
	}
	sort(result.begin(), result.end());
	for (int i = 0; i < n; i++) {
		printf("%d ", result[i].second);
	}
	printf("\n");
}