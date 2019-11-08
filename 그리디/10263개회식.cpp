#include<algorithm>
#include<cstdio>

using namespace std;

int n;
int arr[100001];
int result;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	int saveVal = 0;
	for (int i = 0; i < n; i++) {
		int currentVal = arr[i]-saveVal;
		if (currentVal <= 0)
			continue;
		result++;
		if (currentVal < arr[n - 1]) {
			saveVal++;
		}

	}
	printf("%d\n", result);

}