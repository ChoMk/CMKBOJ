#include<cstdio>
#include<algorithm>
using namespace std;

long long total;
long long win;
long long percent;
long long left;
long long right;

int main() {
	scanf("%lld %lld", &total, &win);
	percent = win * 100 / total;
	if (percent >= 99) {
		printf("-1\n");
		return 0;
	}

	left = 1;
	right = 1000000001;
	while (true) {
		if (left == right)
			break;
		int mid = (left + right) / 2;
		if (percent != (win + mid) * 100 / (total + mid))right = mid;
		else left = mid + 1;
	}
	printf("%lld\n", left);
}