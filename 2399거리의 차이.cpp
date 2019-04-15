#include<cstdio>
#include<algorithm>

using namespace std;

int n;
int arr[10001];
long long result;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result += (long long)abs(arr[i] - arr[j]);
		}
	}
	printf("%lld\n", result);
}