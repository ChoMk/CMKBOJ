#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

int n, m;
int nodeC;
int nodeW;
vector<int> node[403];
int p[403];
int c[403][403];//¿ë·®
int f[403][403];//Èå¸§
int s = 401;
int e = 402;


int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &nodeC);
		for (int j = 0; j < nodeC; j++) {
			scanf("%d", &nodeW);
			nodeW = nodeW + 200;
			node[i].push_back(nodeW - 1);
			node[nodeW - 1].push_back(i);
			c[i][nodeW - 1] = 1;
		}
		c[s][i] = 1;
		node[s].push_back(i);
		node[i].push_back(s);
	}
	for (int i = 200; i < 200 + m; i++) {
		c[i][e] = 1;
		node[e].push_back(i);
		node[i].push_back(e);

	}
	int total = 0;
	while (1) {
		memset(p, -1, sizeof(p));
		queue<int> q;
		q.push(s);
		while (!q.empty() && p[e] == -1) {
			int curr = q.front();
			q.pop();
			for (int i = 0; i < node[curr].size(); i++) {
				int next = node[curr][i];
				if (p[next] == -1 && c[curr][next] - f[curr][next] > 0) {
					q.push(next);
					p[next] = curr;
					if (next == e)break;

				}
			}
		}
		if (p[e] == -1) break;

		for (int i = e; i != s; i=p[i]) {
			f[p[i]][i]++;
			f[i][p[i]]--;
		}
		total++;

	}
	printf("%d\n", total);

}