#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>

using namespace std;

int n;
vector<pair<int, int>> arr;
set<pair<int, int>> visit;
int x, y;
int result;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		arr.push_back({ x,y });
		visit.insert({ x,y });
	}
	for (int i = 0; i < arr.size(); i++) {
		int downLeftX = arr[i].first;
		int downLeftY = arr[i].second;
		for (int j = 0; j < arr.size(); j++) {
			int upRightX = arr[j].first;
			int upRightY = arr[j].second;
			if (downLeftX >= upRightX || downLeftY >= upRightY)
				continue;
			if (!(visit.count({ downLeftX, upRightY }) == 1 && visit.count({ upRightX, downLeftY }) == 1))
				continue;
			result++;
		}
	}
	printf("%d\n", result);
}