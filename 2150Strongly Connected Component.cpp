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
	dfsn[curr] = ++cnt;//�湮 ���� ����.
	S.push_back(curr);//���ÿ� ����

	int result = dfsn[curr];//�湮 ������ �ʱ�ȭ
	for (int i = 0; i<adj[curr].size(); i++)
	{
		int next = adj[curr][i];//���� ���
		if (dfsn[next] == 0) result = min(result, DFS(next));//�湮���� ���� ��� dfs����
		else if (finished[next] == false) result = min(result, dfsn[next]);//�湮�� ��� ������
	}

	if (result == dfsn[curr])//�ٽ� ���� ��� ���� �湮������ ���� ��� ���� ���ÿ��� ���ش�.
	{
		vector<int> currSCC;

		while (true)
		{
			int t = S[S.size() - 1];//������ ���� ���ش�.
			S.pop_back();
			currSCC.push_back(t);
			finished[t] = true;//���ִ� ģ���� ���� ģ���� ������.
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

