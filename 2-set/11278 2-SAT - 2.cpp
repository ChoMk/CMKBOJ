#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;



int cnt;
bool finished[42];
int dfsn[42];
vector<int> S;
vector<int> sccNode[42];
int sccNum[42];
int setResult[42];
int inNode[42];
int sccCnt;
int n, m;
int a, b;
vector<vector<int>> SCC;
bool resultFlag[42];
void resultDFS(int curr) {
	for (int i = 0; i < sccNode[curr].size(); i++) {
		int sccNext = sccNode[curr][i];
		
		resultFlag[sccNext] = true;
		if (sccNext > n) {
			if (setResult[sccNext - n] == -1) {
				setResult[sccNext - n] = 0;
				resultDFS(sccNext);
			}
				
		}
		else {
			if (setResult[sccNext] == -1) {
				setResult[sccNext] = 1;
				resultDFS(sccNext);
			}
				
		}
	
		
		
	}
}
int DFS(int curr) {
	dfsn[curr] = ++cnt;//방문 순서 저장.
	S.push_back(curr);//스택에 저장

	int result = dfsn[curr];//방문 순서로 초기화
	for (int i = 0; i<sccNode[curr].size(); i++)
	{
		int next = sccNode[curr][i];//다음 노드
		if (dfsn[next] == 0) result = min(result, DFS(next));//방문하지 않은 경우 dfs실행
		else if (finished[next] == false) result = min(result, dfsn[next]);//방문한 경우 역방향
	}

	if (result == dfsn[curr])//다시 받은 결과 값과 방문순서가 같은 경우 전부 스택에서 빼준다.
	{
		vector<int> currSCC;
		sccCnt++;
		while (true)
		{
			int t = S[S.size() - 1];//끝에서 부터 빼준다.
			S.pop_back();
			currSCC.push_back(t);
			finished[t] = true;//빼주는 친구는 끝난 친구로 돌린다.
			sccNum[t] = sccCnt;
			if (t == curr)break;
		}
		SCC.push_back(currSCC);

	}
	return result;
}
vector<int> inZeroNode;
int main() {
	memset(setResult, -1, sizeof(setResult));
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		if (a < 0 && b < 0) {
			sccNode[-a].push_back(-b + n);
			sccNode[-b].push_back(-a + n);
		}
		else if (a < 0 && b>0) {
			sccNode[-a].push_back(b);
			sccNode[b + n].push_back(-a + n);
		}
		else if (a > 0 && b < 0) {
			sccNode[n + a].push_back(-b + n);
			sccNode[-b].push_back(a);
			
		}
		else {
			sccNode[n + a].push_back(b);
			sccNode[n + b].push_back(a);
			

		}
	}
	for (int i = 1; i <= n; i++) {
		if (dfsn[i] == 0) {
			DFS(i);
		}
		if (dfsn[i + n] == 0) {
			DFS(i + n);
		}
	}
	
	
	for (int i = 1; i <= n; i++) {
		if (sccNum[i] == sccNum[i + n]) {
			printf("0\n");
			return 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < sccNode[i].size(); j++) {
			int nextScc = sccNode[i][j];
			if (sccNum[nextScc] != sccNum[i]) {
				inNode[sccNum[nextScc]]++;
			}
		}
		for (int j = 0; j < sccNode[i+n].size(); j++) {
			int nextScc = sccNode[i+n][j];
			if (sccNum[nextScc] != sccNum[i+n]) {
				inNode[sccNum[nextScc]]++;
			}
		}
	}
	for (int i = 1; i <= sccCnt; i++) {
		if (inNode[i] == 0) {
			inZeroNode.push_back(i);
		}
	}
	for (int i = 0; i < 1; i++) {//어느게 시작인지 모름
		int node = inZeroNode[i];//scc노드
		for (int j = 1; j <= 2*n; j++) {
			if (sccNum[j] == node) {//scc노드 안에서의 각 노드에대한 것을 부정으로 가정하고 
				if (j > n)
					setResult[j-n] = 1;
				else
					setResult[j] = 0;
				resultFlag[j] = true;
			}
			
		}
		
	}
	for (int i = 1; i <= 2*n; i++) {
		if (resultFlag[i] ==true) {
			resultDFS(i);
		}
	}
	printf("1\n");
	for (int i = 1; i <= n; i++) {
		printf("%d ", setResult[i]);
	}

}