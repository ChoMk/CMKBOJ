#include <cstdio>

#include <vector>

#include <algorithm>

using namespace std;

int T;

int N, M;

int A[1001], B[1001];

vector<int> va, vb;

long long ans;

int main() {

	scanf("%d", &T);

	scanf("%d", &N);

	for (int n = 0; n < N; n++) scanf("%d", &A[n]);

	scanf("%d", &M);

	for (int n = 0; n < M; n++) scanf("%d", &B[n]);



	for (int n = 0; n < N; n++) {

		int sum = 0;

		for (int m = n; m < N; m++) {

			sum += A[m];

			va.push_back(sum);

		}

	}

	for (int n = 0; n < M; n++) {

		int sum = 0;

		for (int m = n; m < M; m++) {

			sum += B[m];

			vb.push_back(sum);

		}

	}

	sort(va.begin(), va.end());

	sort(vb.begin(), vb.end());

	int l = 0, r = vb.size() - 1;

	int asize = va.size();

	while (1) {

		if (va[l] + vb[r] == T) {

			long long acnt = 1, bcnt = 1;

			int ll = l, rr = r;

			while (ll + 1 < asize && va[ll + 1] == va[ll]) acnt++, ll++;

			while (rr - 1 >= 0 && vb[rr - 1] == vb[rr]) bcnt++, rr--;

			ans += acnt * bcnt;

			l = ll + 1;

			r = rr;

		}

		if (l < asize && r >= 0 && va[l] + vb[r] < T)

			l++;

		if (l < asize && r >= 0 && va[l] + vb[r] > T)

			r--;

		if (l >= asize || r < 0) break;

	}

	printf("%lld\n", ans);

	return 0;

}
