#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <functional>
using namespace std;
#pragma warning(disable:4996)
const int INF = 1000000001;
typedef long long ll;

bool check[200001];
vector<int> adj[200001];
int par[200001];
int q[200001];
int ans[200001];
int cnt;

int find(int x)
{
	if (x == par[x])
		return x;
	return par[x] = find(par[x]);
}

bool merge(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return false;
	par[x] = y;
	return true;
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		par[i] = i;
	}
	for (int i = 0; i < M; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i < N; i++)
		scanf("%d", q + i);

	for (int i = N - 1; i >= 0; i--)
	{
		cnt++;
		for (int j = 0; j < adj[q[i]].size(); j++)
		{
			int next = adj[q[i]][j];
			if (check[next])
			{
				if (merge(q[i], next))
				{
					cnt--;
				}
			}
		}
		check[q[i]] = true;
		if (cnt == 1)
			ans[i] = 1;
		else
			ans[i] = 0;
	}
	for (int i = 0; i < N; i++)
	{
		puts(ans[i] ? "YES" : "NO");
	}
	return 0;
}