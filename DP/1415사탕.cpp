#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>

using namespace std;

int n;
int countVal[500001];
long long dp[500001];
int a;
vector<int> arr;
int prime[500001];

void checkPrime() {
	for (int i = 2; i < 500001; i++) {
		if (prime[i] != 0) {
			prime[i]++;
			continue;
		}
		for (int j = i; j < 500001; j = j + i) {
			prime[j]++;
		}
	}
}

int main() {
	checkPrime();
	int zeroCnt = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (a == 0) {
			zeroCnt++;
			continue;
		}

		countVal[a]++;
		if (countVal[a] == 1) {
			arr.push_back(a);
		}
	}
	dp[0] = 1;
	long long result = 0;
	for (int i = 0; i < arr.size(); i++) {
		int currentVal = arr[i];
		int currentCount = countVal[currentVal];
		for (int j = n * 10000; j >= 0; j--) {
			for (int k = 1; k <= currentCount; k++) {
				if (j - currentVal * k < 0)break;
				dp[j] += dp[j - currentVal * k];
			}
		}
	}
	for (int i = 2; i <= n* 10000; i++) {
		if (prime[i] == 1)
			result += dp[i];
	}
	printf("%lld\n", result*zeroCnt);
}