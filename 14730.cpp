#include<cstdio>
#include<algorithm>

int n;
int a, b;
int result;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		if (b == 0)
			continue;
		result += a * (b);
	}
	printf("%d\n", result);

}