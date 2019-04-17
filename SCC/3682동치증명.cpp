#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;
int t;
int n, m;
int u, v;
vector<int> sccNode[20002];//
vector<int> sccStack;//
int nodeIn[20002];//
int nodeOut[20002];//
int sccNodeNum[20002];//
bool finished[20002];//
int dfsn[20002];//
int cnt;//
int sCnt;
int dfs(int curr) {
	dfsn[curr] = ++cnt;
	sccStack.push_back(curr);

	int result = dfsn[curr];
	for (int i = 0; i < sccNode[curr].size(); i++) {
		int Next = sccNode[curr][i];
		if (dfsn[Next] == 0) {
			result = min(result, dfs(Next));
		}
		else if(finished[Next] == false){
			result = min(result, dfsn[Next]);
		}
	}

	if (result == dfsn[curr]) {
		sCnt++;
		while (true) {
			int popVal = sccStack[sccStack.size() - 1];
			sccStack.pop_back();
			finished[popVal] = true;
			sccNodeNum[popVal] = sCnt;
			if (popVal == curr)break;
			
		}
	}
	return result;
}


int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &u, &v);
			sccNode[u].push_back(v);
		}


		for (int i = 1; i <= n; i++) {
			if (dfsn[i] == 0) {
				dfs(i);
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < sccNode[i].size(); j++) {
				int Next = sccNode[i][j];
				
				if (sccNodeNum[i] != sccNodeNum[Next]) {
					nodeOut[sccNodeNum[i]] ++;
					nodeIn[sccNodeNum[Next]]++;
				}
			}
		}
		int nodeInZeroCnt = 0;
		int nodeOutZeroCnt = 0;
		for (int i = 1; i <= sCnt; i++) {
			if (nodeIn[i] == 0)
				nodeInZeroCnt++;
			if (nodeOut[i] == 0)
				nodeOutZeroCnt++;
		}
		if (sCnt == 1) {
			printf("0\n");
		}
		else {
			printf("%d\n", max(nodeInZeroCnt, nodeOutZeroCnt));
		}
		



		for (int i = 1; i <= n; i++) {
		
			sccNode[i].clear();
		}
		
		cnt = 0;
		sccStack.clear();
		memset(nodeIn, 0, sizeof(nodeIn));
		memset(nodeOut, 0, sizeof(nodeOut));
		memset(sccNodeNum, 0, sizeof(sccNodeNum));
		memset(finished, false, sizeof(finished));
		memset(dfsn, 0, sizeof(dfsn));
		sCnt = 0;
	}
}