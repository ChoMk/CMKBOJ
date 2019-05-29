#include<cstdio>
#include<algorithm>

using namespace std;
int n;
long long arr[101];
long long result[1001];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &arr[i]);
		arr[i] *= i;
	}
	for (int i = 1; i <= n; i++) {
		result[i] = arr[i] - arr[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		printf("%lld ", result[i]);
	}
	printf("\n");
}