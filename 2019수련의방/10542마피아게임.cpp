#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;


vector<int> innode[500001];
int outNode[500001];
int n;
int result;
int a;
bool groupState[500001];//true이면 마피아
vector<pair<pair<int, int>, int>> sortCnt;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		innode[a].push_back(i);
		outNode[i]= a;
		
	}
	for (int i = 1; i <= n; i++) {
		sortCnt.push_back({ {innode[i].size(), innode[outNode[i]].size()} , i });
	}
	sort(sortCnt.begin(), sortCnt.end());
	for (int i = 0; i < n; i++) {
		int curr = sortCnt[i].second;
		bool flag = false;
		for (int j = 0; j < innode[curr].size(); j++) {
			if (groupState[innode[curr][j]] == true) {
				flag = true;
				break;
			}

		}
		if (!flag) {
			bool lastFlag = false;
			int nextIDX = outNode[curr];
			if (groupState[nextIDX] == true) {
					lastFlag = true;
					
			}
			
			if(!lastFlag)
				groupState[curr] = true;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (groupState[i])
			result++;
	}

	printf("%d\n", result);
}