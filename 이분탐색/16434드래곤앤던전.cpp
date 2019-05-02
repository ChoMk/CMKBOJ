#include<cstdio>
#include<algorithm>

using namespace std;

int n;
long long sa;//시작 공격력
long long MAXh = 1e18;
long long MINh = 0;
long long arr[123457];
long long t, a, h;

long long fun(long long left, long long right) {
	if (left > right)
		return left;
	long long mid = (left + right) / 2;
	long long tempHP = mid;
	for (int i = 0; i < n; i++) {
		tempHP += arr[i];
		if (tempHP > mid)
			tempHP = mid;
		if (tempHP <= 0) {
			break;
		}
	}
	if (tempHP < 1) {
		return fun(mid + 1, right);
	}
	else if (tempHP > 1) {
		return fun(left, mid - 1);
	}
	else {
		return mid;
	}
}


int main() {
	scanf("%d %lld", &n, &sa);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld %lld", &t, &a, &h);
		if (t == 1) {
			
			arr[i] = -(((h-1) / sa)*a);
			
		}
		else {
			sa += a;
			arr[i] = h;
		}
	}
	printf("%lld\n", fun(MINh, MAXh));
}