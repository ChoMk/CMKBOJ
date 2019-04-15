#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;
int n;
int m;
vector<int> save[51];
int r;
bool visit[51];
int p[51];
int a;
int dfs(int idx) {
	if (idx == m) {
		if (save[p[idx]].size() == 1)
			return 1;
		return 0;
	}
	
	int re = 0;
	if (save[idx].size() == 0)
		return 1;
	for (int i = 0; i < save[idx].size(); i++) {
		
		int nextIDX = save[idx][i];
		
		if (visit[nextIDX] == true)
			continue;
		visit[nextIDX] = true;
		
		re += dfs(nextIDX);

	}
	
	return re;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		p[i] = a;
		if (a == -1)
		{
			r = i;
			continue;
		}
			
		save[a].push_back(i);
	}
	scanf("%d", &m);
	visit[r] = true;
	int result = dfs(r);
	printf("%d\n", result);

}