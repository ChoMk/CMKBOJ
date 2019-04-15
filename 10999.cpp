#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
typedef long long ll;

ll seg[4040000];
ll lazy[4040000];
ll n, m, k;
ll a, b, c, d;
ll tmp;

void propagation(ll node, ll x, ll y) {
	if (lazy[node]) {
		seg[node] += (y - x + 1)*lazy[node];
		if (x == y) {
			lazy[node] = 0;
			return;
		}
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
		lazy[node] = 0;
	}
}

ll update(ll lo, ll hi, ll val, ll node, ll x, ll y) {
	propagation(node, x, y);
	if (y < lo || hi < x)	return seg[node];
	if (lo <= x && y <= hi) {
		lazy[node] += val;
		propagation(node, x, y);
		return seg[node];
	}
	ll mid = (x + y) >> 1;

	return seg[node] = update(lo, hi, val, node * 2, x, mid) + update(lo, hi, val, node * 2 + 1, mid + 1, y);;
}

ll query(ll lo, ll hi, ll node, ll x, ll y) {
	propagation(node, x, y);
	if (hi < x || y < lo)	return 0;
	if (lo <= x && y <= hi)	return seg[node];
	ll mid = (x + y) >> 1;
	return query(lo, hi, node * 2, x, mid) + query(lo, hi, node * 2 + 1, mid + 1, y);
}

int main() {

	scanf("%lld %lld %lld", &n, &m, &k);

	for (int i = 0; i < n; i++) {
		scanf("%lld", &tmp);
		update(i, i, tmp, 1, 0, n - 1);
	}
	for (int i = 0; i < m + k; i++) {
		scanf("%lld", &a);

		if (a == 1) {
			scanf("%lld %lld %lld", &b, &c, &d);
			--b; --c;
			update(b, c, d, 1, 0, n - 1);
		}
		else {
			scanf("%lld %lld", &b, &c);
			--b; --c;
			printf("%lld\n", query(b, c, 1, 0, n - 1));
		}
	}

}