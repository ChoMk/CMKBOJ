#include<cstdio>
#include<algorithm>
using namespace std;

int arr[100001];
int n;
int m;
int result = 987654321;
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
			result = min(result, right - left);
			sum += arr[++right];
		}
		else if (sum < m) {
			sum += arr[++right];
		}
		else if (sum > m) {
			result = min(result, right - left);
			sum -= arr[left++];

		}
	}
	if (result == 987654321)
		printf("0\n");
	else
		printf("%d\n", result+1);
}