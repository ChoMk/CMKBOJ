#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>

using namespace std;
long long MOD = 1000000007;
vector<int> arr[100001];
bool visit[100001];
int n, k;
long long kColor[100001];
long long dp[100001][4];
long long a, b;
long long fun(int curNode, int color) {
	
	long long &reg = dp[curNode][color];
	if (reg != -1)
		return reg;
	reg = 1;
	visit[curNode] = true;
	for (int i = 0; i < arr[curNode].size(); i++) {
		
		int nextNode = arr[curNode][i];
		if (visit[nextNode])
			continue;
		if (kColor[nextNode] == color) {
			visit[curNode] = false;
			return reg = 0;
		}
			
		if (kColor[nextNode] != 0) {
			reg *= fun(nextNode, kColor[nextNode]);
			reg %= MOD;
			continue;
		}
		long long temp = 0;
		for (int j = 1; j <= 3; j++) {
			if (j == color)
				continue;
			temp += fun(nextNode, j);
			temp %= MOD;
		}
		reg *= temp;
		reg %= MOD;
	}
	visit[curNode] = false;
	return reg;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n-1; i++) {
		scanf("%d %d", &a, &b);
		a--;
		b--;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &a, &b);
		a--;
		kColor[a] = b;
	}
	long long result = 0;
	if (kColor[0] == 0) {
		result += fun(0, 1);
		result %= MOD;
		result += fun(0, 2);
		result %= MOD;
		result += fun(0, 3);
		result %= MOD;
	}
	else {
		result += fun(0, kColor[0]);
	}
	printf("%lld\n", result);
}