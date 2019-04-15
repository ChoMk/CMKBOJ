#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_F = 50;
const long long INF = 1e18;

inline int sign(int k) { return k % 2 ? -1 : 1; }

int main() {
	long long f[MAX_F] = { 0, 1 };
	for (int i = 2; i<MAX_F; i++)
		f[i] = f[i - 1] + f[i - 2];

	int T;
	scanf("%d", &T);
	for (int t = 0; t<T; t++) {
		int N;
		scanf("%d", &N);
		long long a = 1, b = N - 1;

		for (int i = 2; f[i + 1] < N; i++) {
			long long r1 = f[i], r2 = f[i+1], s1 = 1, s2 = 0, t1 = 0, t2 = 1;
			
			while (r2) {
				int q = r1 / r2;
				if (r1 < 0 && r1%r2) q--;//�� ���ô� A, B�� ����� ���� ���������, r�� �ݵ�� 0 �̻� |r2| �̸��� ������ �Ǿ�� �մϴ�. ���� ������ ��� ���������� ��Ģ�� �׷����ϴ�.

										 //�� 9 / -4�� ���� - 2�� �ƴ϶� - 3�Դϴ�. 9 - (-4 * -3)�� �ؾ� �������� 3, �� 0 �̻� 4 �̸��� ������ ������ �����Դϴ�.

				long long r = r1 - q * r2; r1 = r2; r2 = r;
				long long s = s1 - q * s2; s1 = s2; s2 = s;
				long long t = t1 - q * t2; t1 = t2; t2 = t;
			}
			long long d = r1;
			long long s = s1;
			long long t = t1;
			
			if (N%d != 0)
				continue;
			
			long long x0 = s * N / d;
			long long y0 = t * N / d;
			if (x0 < a && (y0 < b||y0==b)) {
				a = x0;
				b = y0;
			}
		}
		printf("%lld %lld\n", a, b);
	}
}