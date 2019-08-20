#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>

using namespace std;

int t;
bool visit[1000001];
int a, b;
int n;
int arr[1000001];

int fun(int cur) {
	visit[cur] = true;
	queue<int> q;
	int result = 987654321;
	q.push(cur);
	int lay = 0;
	while (!q.empty()) {
		int qSize = q.size();

		for (int i = 0; i < qSize; i++) {
			int curNode = q.front();

			q.pop();
			if (arr[curNode] == 1 && a <= curNode && curNode <= b) {
				return lay;
			}
			if (curNode / 2 > 0 && !visit[curNode / 2]) {
				visit[curNode / 2] = true;
				q.push(curNode / 2);

			}
			if (curNode / 3 > 0 && !visit[curNode / 3]) {
				visit[curNode / 3] = true;
				q.push(curNode / 3);

			}
			if (curNode - 1 > 0 && !visit[curNode - 1]) {
				visit[curNode - 1] = true;
				q.push(curNode - 1);

			}
			if (curNode + 1 <1000001 && !visit[curNode + 1]) {
				visit[curNode + 1] = true;
				q.push(curNode + 1);

			}


		}
		lay++;
	}
	return 987654321;
}

int main() {
	for (int i = 2; i < 1000001; i++) {
		arr[i]++;
		if (arr[i] == 1) {
			for (int j = 2; i*j<1000001; j++) {
				arr[i*j]++;
			}
		}
	}

	scanf("%d", &t);
	while (t--) {

		memset(visit, false, sizeof(visit));
		scanf("%d %d %d", &n, &a, &b);
		bool flag = false;

		for (int i = a; i <= b; i++) {
			if (arr[i] == 1)
				flag = true;
		}
		if (!flag) {
			printf("-1\n");
			continue;
		}
		int result = fun(n);


		printf("%d\n", result);

	}
}