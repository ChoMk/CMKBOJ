#include<iostream>
#include<algorithm>

using namespace std;


int lca(int u, int v) {
	if (dep[u] > dep[v])
		swap(u, v);
	for (int i = 19; i >= 0; i--) {
		int diff = dep[v] - dep[u];
		if (diff >= (1 << i))
			v = parent[i][v];

	}
	if (u == v)
		return u;
	for (int i = 19; i >= 0; i--) {
		if (parent[i][u] != parent[i][v]) {
			u = parent[i][u];
			v = parent[i][v];
		}
	}
	return parent[0][u];
}