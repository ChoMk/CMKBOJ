#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<cstdio>


using namespace std;

int n;
int startNode;
int a, b;
int visit[100001];
vector<int> node[100001];
int result;
queue<pair<int, bool>> q;

void fun() {

	while (!q.empty()) {
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			int curNode = q.front().first;
			bool curState = q.front().second;
			q.pop();
			
			for (int j = 0; j < node[curNode].size(); j++) {
				int nextNode = node[curNode][j];
			
				if (visit[nextNode] !=0) {
					if (curState &&visit[nextNode] ==1)
						result++;
					continue;
				}
				if (curState)
					visit[nextNode] = 2;
				else
					visit[nextNode] = 1;

				q.push({nextNode, curState });
			}
				

		}
	}
}


int main() {
	scanf("%d %d", &n, &startNode);
	startNode--;
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d", &a, &b);
		a--;
		b--;
		node[a].push_back(b);
		node[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		if (i != startNode && node[i].size() == 1) {
			visit[i] = 1;
			q.push({ i, false });

		}
	}
	visit[startNode] = 2;
	q.push({ startNode, true});
	fun();
	printf("%d\n", result);
}