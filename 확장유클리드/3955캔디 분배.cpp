#include <cstdio>
#include <cmath>
#include <algorithm>
const int MAX = 1e9;
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	for (int tt = 0; tt<T; tt++) {
		int a, b, d, s, t;
		scanf("%d %d", &a, &b);
		if (b == 1) {
			if (a == MAX) puts("IMPOSSIBLE");
			else printf("%d\n", a + 1);
			continue;
		}

		b *= -1;//양수, 음수의 서로소의 경우 최대 공약수가 -1이 된다.
		int r1 = a, r2 = b, s1 = 1, s2 = 0, t1 = 0, t2 = 1;
		while (r2) {
			int q = r1 / r2;
			if (r1 < 0 && r1%r2) q--;//이 예시는 A, B가 양수라 별로 상관없지만, r은 반드시 0 이상 |r2| 미만의 정수가 되어야 합니다. 원래 정수론 등에서 나머지값의 규칙이 그렇습니다.

	//즉 9 / -4의 몫은 - 2가 아니라 - 3입니다.  (-4 * -3)-9을 해야 나머지가 3, 즉 0 이상 4 미만의 값으로 들어오기 때문입니다.

			int r = r1 - q * r2; r1 = r2; r2 = r;
			int s = s1 - q * s2; s1 = s2; s2 = s;
			int t = t1 - q * t2; t1 = t2; t2 = t;
		}
		d = r1; s = s1; t = t1;

		if (abs(d) > 1) puts("IMPOSSIBLE");
		else {
			int k1 = s / b - 1; 
			if (s < 0 && s%b) 
				k1++;//부등식 처리
			int k2 = -t / a; 
			if (t >= 0 && t%a) 
				k2--;//부등식 처리
			int k = min(k1, k2);//k의 최댓값 찾기...
			if (-t - 1LL * k*a <= MAX) printf("%lld\n", -t - 1LL * k*a);
			else puts("IMPOSSIBLE");
		}
	}
}