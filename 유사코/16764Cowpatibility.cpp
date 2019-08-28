#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>

using namespace std;

long long n;
long long arr[50001][6];
vector<int> IDCnt[1000001];
long long total;
long long compatible;
int visit[50001];
int main() {

	scanf("%lld", &n);
	for (int i = 1; i <= n - 1; i++) {
		total += i;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%lld", &arr[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		int curPairCnt = 0;
		for (int j = 0; j < 5; j++) {
			int curID = arr[i][j];
			for (int k = 0; k < IDCnt[curID].size(); k++) {

				if (curPairCnt == i)
					break;
				if (visit[IDCnt[curID][k]] != (i + 1)) {
					total--;
					curPairCnt++;
					visit[IDCnt[curID][k]] = (i + 1);
				}
			}
			IDCnt[curID].push_back(i);
		}

	}
	printf("%lld\n", total);
}