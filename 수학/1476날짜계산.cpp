#include<cstdio>
#include<algorithm>

using namespace std;

int a, b, c;
int result;
int sa, sb, sc;

int main() {
	scanf("%d %d %d", &a, &b, &c);
	while(true) {
		if (a == sa && b == sb && c == sc) {
			break;
		}
		sa++;
		sb++;
		sc++;
		result++;
		if (sa == 16) {
			sa = 1;
		}
		if (sb == 29) {
			sb = 1;
		}
		if (sc == 20) {
			sc = 1;
		}
	}
	printf("%d\n", result);
}