#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;


int t;
int n;
int c;

int arr[1000001];

int main() {
	int caseCnt = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
			
		}
		sort(arr, arr + n);
		int result = 0;
		int MaxDum = arr[n - 1];
		int MaxSum = arr[n - 1];
		int MinDum = arr[0];
		for (int i = n-2; i > 0; i--) {
			MaxDum ^= arr[i];
			MaxSum += arr[i];
		}
		for (int i = 0; i < n - 1; i++) {
			if (MaxDum == MinDum) {
				result = max(result, MaxSum);
			}
			MaxDum ^= arr[i+1];
			MinDum ^= arr[i+1];
			MaxSum -= arr[i+1];
		}
		if (result == 0) {
			printf("Case #%d: NO\n", caseCnt);
		}
		else {
			printf("Case #%d: %d\n", caseCnt, result);
		}
		caseCnt++;
	}
}