#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
int n, k;
string state[100001];
int s, e;
bool visit[100001];
int trace[100001];
int t;

int main() {

	std::ios::sync_with_stdio(false);

	cin >> n >> k;
	
	for (int i = 1; i <= n; i++) {
		cin >> state[i];
	}
	queue<int> saveQ;
	s = 1;
	saveQ.push(s);
	visit[s] = true;

	while (true) {
		if (saveQ.size() == 0) {
			break;

		}
		int presentIdx = saveQ.front();
		saveQ.pop();
		for (int i = 1; i <= n; i++) {
			if (visit[i] == true)
				continue;
			int cmpCnt = 0;
			for (int j = 0; j < k; j++) {
				if (state[presentIdx][j] != state[i][j])
					cmpCnt++;
			}
			if (cmpCnt == 1) {
				saveQ.push(i);
				visit[i] = true;
				trace[i] = presentIdx;
			}

		}
	}
	cin >> t;
	while (t--) {
		cin >> e;
		vector<int> result;
		
		if (visit[e] == false)
		{
			cout << "-1\n";

		}
		else {
			int resultPresent = e;
			result.push_back(resultPresent);
			while (true) {
				if (resultPresent == s)
					break;
				resultPresent = trace[resultPresent];
				result.push_back(resultPresent);
			}
			reverse(result.begin(), result.end());
			for (int i = 0; i < result.size(); i++)
			{
				cout << result[i] << " ";
			}
			cout << "\n";
		}
	}
	
}