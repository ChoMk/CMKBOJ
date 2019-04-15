#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
int n;
int k;
int arr[5000001];

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	printf("%d\n", arr[k - 1]);
}