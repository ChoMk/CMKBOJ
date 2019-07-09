#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
int n;
int arr[1001][2];
bool visit[1002];
vector<pair<int, int>> node[1001];
int result;

int dist(int x1, int y1, int x2, int y2) {
	return (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
}

void MST() {
	priority_queue<pair<int, int>> pq;
	for (int i = 0; i < node[0].size(); i++) {
		pq.push({ -node[0][i].second, node[0][i].first });
	}
	int cntNode = 1;
	visit[0] = true;
	while (true) {
		if (cntNode == n)
			break;
		int curVal = -1;
		int curNode = -1;
		while (true) {
			if (pq.empty())
				break;
			curVal = -pq.top().first;
			curNode = pq.top().second;
			if (!visit[curNode])
				break;
			pq.pop();
		}
		result = max(curVal, result);
		visit[curNode] = true;
		cntNode++;
		for (int i = 0; i < node[curNode].size(); i++) {
			pq.push({ -node[curNode][i].second, node[curNode][i].first });
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i][0], &arr[i][1]);
		arr[i][0]--;
		arr[i][1]--;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)
				continue;
			node[i].push_back({ j, dist(arr[i][0], arr[i][1], arr[j][0], arr[j][1]) });
		}
	}
	MST();
	printf("%d\n", result);


}