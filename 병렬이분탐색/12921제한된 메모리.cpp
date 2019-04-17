#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <memory.h>

using namespace std;

using ll = long long;

int query[1000];
int lo[1000];
int hi[1000];
int mid[1000];

const ll p = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, x0, a, b;
	cin >> N >> x0 >> a >> b;
	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> query[i];
		query[i]++;
	}

	fill(hi, hi + m, p - 1);
	fill(mid, mid + m, (p - 1) >> 1);
	sort(query, query + m);

	for (int z = p; z; z >>= 1) {

		vector<int> count(m + 1);

		ll x = x0;
		for (int i = 0; i < N; i++) {
			int v = lower_bound(mid, mid + m, x) - mid;
			count[v]++;
			x = (x * a + b) % p;
		}
		//x가 몇번째 쿼리에 처음으로 속하는지
		for (int i = 1; i < m + 1; i++)
			count[i] += count[i - 1];
		//그전 쿼리를 더해줘야 현제 카운트를 할 수 있다.
		for (int i = 0; i < m; i++) {
			if (lo[i] == hi[i]) continue;
			if (count[i] > query[i])
				hi[i] = mid[i] - 1;
			else if (count[i] < query[i])
				lo[i] = mid[i] + 1;
			else
				hi[i] = mid[i];
			mid[i] = (lo[i] + hi[i]) >> 1;
		}
	}

	ll sum = 0;
	for (int i = 0; i < m; i++)
		sum += lo[i];
	cout << sum;

	return 0;
}