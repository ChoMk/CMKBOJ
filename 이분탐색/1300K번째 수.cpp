#include<algorithm>
#include<cstdio>
#include<vector>

using namespace std;

long long n, k;

int main() {
	scanf("%lld %lld", &n, &k);
	long long left = 1;
	long long right = 1000000000;
	long long result;
	while (left <= right) {
		int cnt = 0;
		long long mid = (left + right) / 2;
		for (int i = 1; i <= n; i++) {
			cnt += min(mid / i, n);
		}
		if (cnt < k) {
			left = mid + 1;
		}
		else {
			result = mid;
			right = mid - 1;
		}
	}
	printf("%lld\n", result);
}