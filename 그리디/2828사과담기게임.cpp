#include<cstdio>
#include<algorithm>

using namespace std;

int n, m, J;
int a;
int bs, be;
int result;



int main() {
	scanf("%d %d", &n, &m);
	m--;
	bs = 1;
	be = 1+m;
	scanf("%d", &J);
	for (int i = 0; i < J; i++) {
		scanf("%d", &a);
		if (bs <= a && a <= be) {
			continue;
		}
		int bsd = abs(a - bs);
		int bed = abs(a - be);
		if (bs>a) {
			result += bsd;
			bs = a;
			be = bs + m;
		}
		else {
			result += bed;
			be = a;
			bs = be - m;
		}
	}
	printf("%d\n", result);
}