#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

int n, h;
vector<pair<pair<int, int>, int>> arr;
int a, b, c;
int fun(int curidx, int curh, int curRest) {
	if (curh >= h)
		return curRest;
	if (curidx == n)
		return -1;
	int result = -1;
	for (int i = curidx; i < n; i++) {
		if (curRest >= arr[i].first.second) {
			result = max(result, fun(i + 1, curh + arr[i].second, min(curRest - arr[i].first.second, arr[i].first.first - arr[i].first.second)));
		}

	}
	return result;
}
int main() {
	scanf("%d %d", &n, &h);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		arr.push_back({ { c+b, b }, a });//�Ŀ��� ūģ���� �������� �״����� ���԰� ū ģ���� �������� �״��� Ű
	}
	sort(arr.begin(), arr.end());
	reverse(arr.begin(), arr.end());
	int temp = fun(0, 0, 1000000001);
	if (temp == -1) {
		printf("Mark is too tall\n");
	}
	else {
		printf("%d\n", temp);
	}

}