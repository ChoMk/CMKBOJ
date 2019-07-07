#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
using namespace std;
int n;
int arr[500001];
long long result = 0;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		
	}
	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		result += (long long)abs(i - arr[i] + 1);
	}
	printf("%lld\n", result);
}