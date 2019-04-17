#include<cstdio>
#include<algorithm>

using namespace std;

unsigned long long a;
unsigned long long b;
unsigned long long c;

unsigned long long fun(unsigned long long h) {
	if (h == 0)
		return 1;
	if (h % 2 == 1) {
		return fun(h / 2)*fun(h / 2) % c*a%c;
	}
	else {
		return fun(h / 2)*fun(h / 2) % c;
	}

}


int main() {
	scanf("%llu %llu %llu", &a, &b, &c);
	printf("%llu\n", fun(b));
}