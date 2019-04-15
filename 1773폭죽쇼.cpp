#include<cstdio>
#include<algorithm>

using namespace std;

int n;
int c;
int arr[101];
int result[2000001];
int a;
int anw;
int main() {
	scanf("%d %d", &n, &c);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		if (i != 0 && arr[i] == arr[i - 1])
			continue;
		int tempGA = arr[i];
		while (true) {
			if (tempGA > c)
				break;
			result[tempGA] = 1;
			tempGA += arr[i];
		}
	}
	for (int i = 0; i <= c; i++) {
		anw += result[i];
	}
	printf("%d\n", anw);
}