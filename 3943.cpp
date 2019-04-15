#include <cstdio>
#include <algorithm>

using namespace std;

int d[100001];

int f(int x) {
	if (x <= 100000) {
		if (d[x]) return d[x];
		return d[x] = max(x, x & 1 ? f(x * 3 + 1) : f(x >> 1));
	}
	return max(x, x & 1 ? f(x * 3 + 1) : f(x >> 1));
}

int main() {
	int T;
	scanf("%d", &T);
	d[1] = 1;
	while (T--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", f(n));
	}
}