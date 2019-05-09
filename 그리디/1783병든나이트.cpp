#include<cstdio>
#include<algorithm>

using namespace std;


int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	if (n == 1) return puts("1"), 0;
	if (n == 2) return printf("%d", min(4, (m + 1) / 2)), 0;
	if (m < 7) return printf("%d", min(4, m)), 0;
	printf("%d", m - 7 + 5);
}