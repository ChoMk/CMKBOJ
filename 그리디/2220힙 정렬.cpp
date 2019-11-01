#include<cstdio>
int n, a[100001];
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		for (int j = i; j > 1; j /= 2) a[j] = a[j / 2];
		a[1] = i + 1;
	}
	a[n] = 1;
	for (int i = 1; i <= n; i++) printf("%d ", a[i]);
	return 0;
}