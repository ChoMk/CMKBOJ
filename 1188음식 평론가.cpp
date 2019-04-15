#include <cstdio>
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
int main() {
	int N, M, ans = 0;
	scanf("%d%d", &N, &M);
	printf("%d\n", M - gcd(N, M));
	return 0;
}