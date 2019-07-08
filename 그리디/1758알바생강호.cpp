#include<cstdio>
#include<algorithm>

using namespace std;

int n;
long long result;
int arr[100001];


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	reverse(arr, arr + n);
	for (int i = 0; i < n; i++) {
		long long temp = arr[i] - i;
		if (temp < 0) {
			temp = 0;
		}
		result += temp;
	}
	printf("%lld\n", result);
}