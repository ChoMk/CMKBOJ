#include<cstdio>

using namespace std;

int n, m, k;

int main() {
	scanf("%d %d %d", &n, &m, &k);
	printf("%d\n", k / (2 * n)*m);
}