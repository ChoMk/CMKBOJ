#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

int dp[1101][1101];
int dpTrace[1101][1101];

int n;
int w;
int a, b;
vector<pair<int, int>> arr;
int fun(int fidx, int sidx) {

	if (fidx == w+1 || sidx == w+1)
		return 0;

	int &reg = dp[fidx][sidx];

	if (reg != -1)
		return reg;

	int nextIDX = max(fidx, sidx) + 1;
	int pickf = fun(nextIDX, sidx) + abs(arr[fidx].first - arr[nextIDX].first) + abs(arr[fidx].second - arr[nextIDX].second);
	int picks = fun(fidx, nextIDX) + abs(arr[sidx].first - arr[nextIDX].first) + abs(arr[sidx].second - arr[nextIDX].second);

	reg = min(pickf, picks);

	if (reg == pickf) {
		dpTrace[fidx][sidx] = 1;
	}
	else {
		dpTrace[fidx][sidx] = 2;
	}
	
	return reg;


}

int main() {
	memset(dp, -1, sizeof(dp));
	memset(dpTrace, -1, sizeof(dpTrace));
	scanf("%d", &n);
	scanf("%d", &w);
	arr.push_back({ 1, 1 });
	arr.push_back({ n,n });
	for (int i = 0; i < w; i++) {
		scanf("%d %d", &a, &b);
		arr.push_back({ a,b });
	}
	printf("%d\n", fun(0, 1));
	int curf = 0;
	int curs = 1;
	int nextIDX = 2;
	int pickpol = dpTrace[0][1];

	while(true) {

		if (nextIDX == w + 2)
			break;
		printf("%d\n", pickpol);
		if (pickpol == 1) {
			curf = nextIDX;
			
		}
		else {
			curs = nextIDX;
		}
		pickpol = dpTrace[curf][curs];
		nextIDX++;
	}
	
}