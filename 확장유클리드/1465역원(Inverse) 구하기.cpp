#include<cstdio>
#include<algorithm>

using namespace std;

long long n, a;
long long a1, a2, a3;
long long b1, b2, b3;
long long t1, t2, t3;


long long exgcd(long long m, long long b) {
	a1 = 1;
	a2 = 0;
	a3 = m;
	b1 = 0;
	b2 = 1;
	b3 = b;
	while (true) {
		if (b3 == 0)
			return -1;
		if (b3 == 1){
			while (true) {
				if (b2 > 0)
					break;
				b2 += m;
			}
			return b2;
		}
		long long q = a3 / b3;
		t1 = a1 - q * b1;
		t2 = a2 - q * b2;
		t3 = a3 - q * b3;
		a1 = b1;
		a2 = b2;
		a3 = b3;

		b1 = t1;
		b2 = t2;
		b3 = t3;

	}
}

int main() {
	scanf("%lld %lld", &n, &a);
	printf("%lld ", n - a);
	printf("%lld\n", exgcd(n, a));
}