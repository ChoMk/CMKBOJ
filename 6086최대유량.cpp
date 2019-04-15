#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
#include<iostream>
using namespace std;

int n;
char u, v;
int w;
int c[53][53];//간선간 한도
int f[53][53];//간선에 흐르는 양
vector<int> node[53];//간선 저장
int p[53];//전에 갔던 위치

int CtoI(char c) {

	if (c <= 'Z')return c - 'A';
	return c - 'a' + 26;


}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin.ignore(1);
		scanf("%c %c %d", &u, &v, &w);
		u = CtoI(u);
		v = CtoI(v);
		c[u][v] += w;
		c[v][u] += w;// 같은 간선 2번

		node[u].push_back(v);
		node[v].push_back(u);
		

	}
	int total = 0;
	int S = CtoI('A');
	int E = CtoI('Z');

	while (1) {
		memset(p, -1, sizeof(p));
		queue<int> q;
		q.push(S);
		while (!q.empty() && p[E] == -1) {
			int curr = q.front();
			q.pop();
			for (int i = 0; i < node[curr].size(); i++) {
				if (c[curr][node[curr][i]] - f[curr][node[curr][i]] > 0 && p[node[curr][i]] == -1) {
					q.push(node[curr][i]);
					p[node[curr][i]] = curr;
					if (node[curr][i] == E)
						break;

				}
			}
		}

		if (p[E] == -1) break;


		int flow = 987654321;
		for (int i = E; i != S; i = p[i]) {
			flow = min(flow, c[p[i]][i] - f[p[i]][i]);
		}
		for (int i = E; i != S; i = p[i]) {
			f[p[i]][i] += flow;
			f[i][p[i]] -= flow;
		}

		total += flow;

	}
	printf("%d\n", total);

}