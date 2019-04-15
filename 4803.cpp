#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int n, m;
int cnt = 1;
bool visit[501];

void fun(int Tn, int Tm, int Tcnt) {
	vector<int> save[501];
	int a, b;
	memset(visit, false, sizeof(visit));
	for (int i = 0; i < Tm; i++) {
		scanf("%d %d", &a, &b);
		save[a].push_back(b);
		save[b].push_back(a);
	}
	int result = 0;
	for (int i = 1; i <= Tn; i++) {
		if (visit[i] == true)
			continue;
		visit[i] = true;
		int edgeCnt = 0;
		int node = 0;
		queue<int> bfs;
		bfs.push(i);
		int sw = 0;
		while (true) {
			if (bfs.size() == 0)
				break;
			int presentI = bfs.front();
			bfs.pop();
			node++;
			for (int i = 0; i < save[presentI].size(); i++) {
				if (visit[save[presentI][i]] != true)
				{
					visit[save[presentI][i]] = true;
					bfs.push(save[presentI][i]);

				}
				edgeCnt++;
			}
		}
		if (node-1 != edgeCnt/2)
			sw = 1;
		if (sw == 0)
			result++;

	}
	if (result == 0) {
		printf("Case %d: No trees.\n", Tcnt);
	}
	else if (result == 1) {
		printf("Case %d: There is one tree.\n", Tcnt);
	}
	else {
		printf("Case %d: A forest of %d trees.\n", Tcnt, result);
	}


}


int main() {
	
	while (true) {
		scanf("%d %d", &n, &m);
		if (n == 0)
			break;
		
		fun(n, m, cnt);
		cnt++;
	}



}