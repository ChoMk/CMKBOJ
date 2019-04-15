#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX = 10001;

int V, E, cnt, dfsn[MAX], SN;
vector<int> adj[MAX];
bool finished[MAX];
vector<int>S;
vector<vector<int>> SCC;

int DFS(int curr)
{
	dfsn[curr] = ++cnt;//방문 순서 저장.
	S.push_back(curr);//스택에 저장

	int result = dfsn[curr];//방문 순서로 초기화
	for (int i = 0; i<adj[curr].size(); i++)
	{
		int next = adj[curr][i];//다음 노드
		if (dfsn[next] == 0) result = min(result, DFS(next));//방문하지 않은 경우 dfs실행
		else if (finished[next] == false) result = min(result, dfsn[next]);//방문한 경우 역방향
	}

	if (result == dfsn[curr])//다시 받은 결과 값과 방문순서가 같은 경우 전부 스택에서 빼준다.
	{
		vector<int> currSCC;

		while (true)
		{
			int t = S[S.size() - 1];//끝에서 부터 빼준다.
			S.pop_back();
			currSCC.push_back(t);
			finished[t] = true;//빼주는 친구는 끝난 친구로 돌린다.
			//sn[t] = SN;
			if (t == curr)break;
		}
		sort(currSCC.begin(), currSCC.end());

		SCC.push_back(currSCC);
		SN++;
	}
	return result;
}

int main()
{
	scanf("%d %d", &V, &E);
	for (int i = 0; i<E; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
	}
	for (int i = 0; i<V; i++)
	{
		if (dfsn[i + 1] == 0) DFS(i + 1);
	}
	sort(SCC.begin(), SCC.end());
	printf("%d\n", SN);
	for (int i = 0; i<SCC.size(); i++)
	{
		for (int j = 0; j<SCC[i].size(); j++)
		{
			printf("%d ", SCC[i][j]);
		}
		printf("-1\n");
	}
}

