#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;



int cnt;
bool finished[42];
int dfsn[42];
vector<int> S;
vector<int> sccNode[42];
int sccNum[42];
int sccCnt;
int n, m;
int a, b;
int DFS(int curr) {
	dfsn[curr] = ++cnt;//�湮 ���� ����.
	S.push_back(curr);//���ÿ� ����

	int result = dfsn[curr];//�湮 ������ �ʱ�ȭ
	for (int i = 0; i<sccNode[curr].size(); i++)
	{
		int next = sccNode[curr][i];//���� ���
		if (dfsn[next] == 0) result = min(result, DFS(next));//�湮���� ���� ��� dfs����
		else if (finished[next] == false) result = min(result, dfsn[next]);//�湮�� ��� ������
	}

	if (result == dfsn[curr])//�ٽ� ���� ��� ���� �湮������ ���� ��� ���� ���ÿ��� ���ش�.
	{
		vector<int> currSCC;
		sccCnt++;
		while (true)
		{
			int t = S[S.size() - 1];//������ ���� ���ش�.
			S.pop_back();
			currSCC.push_back(t);
			finished[t] = true;//���ִ� ģ���� ���� ģ���� ������.
			sccNum[t] = sccCnt;
			if (t == curr)break;
		}
		
		
	}
	return result;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		if (a < 0 && b < 0) {
			sccNode[-a].push_back(-b + 20);
			sccNode[-b].push_back(-a + 20);
		}
		else if (a < 0 && b>0) {
			sccNode[-a].push_back(b);
			sccNode[b + 20].push_back(-a + 20);
		}
		else if (a > 0 && b < 0) {
			sccNode[20 + a].push_back(-b + 20);
			sccNode[-b].push_back(a);
		}
		else {
			sccNode[20 + a].push_back(b);
			sccNode[20 + b].push_back(a);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (dfsn[i] == 0) {
			DFS(i);
		}
		if (dfsn[i + 20] == 0) {
			DFS(i + 20);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (sccNum[i] == sccNum[i + 20]) {
			printf("0\n");
			return 0;
		}
	}
	printf("1\n");


}