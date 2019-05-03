#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
long long arr[300001];

int n;
int k;
vector<int> idxk;
long long result = 100000000000000000;
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	idxk.push_back(n - k+1);
	for (int i = 0; i < k-1; i++) {
		idxk.push_back(1);
	}
	int trig = 0;
	if (k == 1) {
		printf("%d\n", arr[n - 1] - arr[0]);
		return 0;
	}
	while (true) {
		
		long long tempR = (arr[idxk[0]-1] - arr[0]);
		int preIDX = idxk[0];
		for (int i = 1; i < k; i++) {
			tempR += (arr[idxk[i] + preIDX - 1] - arr[preIDX]);
			preIDX += idxk[i];
		}
		result = min(result, tempR);
		if (idxk[trig] == 1) {
			trig++;
			if (trig == k - 1)
				break;
		}
		
		idxk[trig]--;
		idxk[trig + 1]++;
		
	}
	printf("%lld\n", result);
}