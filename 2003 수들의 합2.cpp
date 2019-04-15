#include<cstdio>
#include<algorithm>
using namespace std;

int arr[10001];
int n;
int m;
int result;
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	int left = 0;
	int right = 0;
	int sum = arr[0];
	while (1) {
		if (right == n)break;
		if (sum == m) {
			result++;
			sum += arr[++right];
		}
		else if (sum < m)sum += arr[++right];
		else if (sum > m)sum -= arr[left++];
	}
	printf("%d\n", result);
}