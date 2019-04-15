#include <cstdio>
#include <set>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int n;
int pre[1003];
int in[1003];
int pr[1003];
int ir[1003];
void post(int ps, int is, int sz)
{
	if (sz <= 0)return;
	int root = pre[ps];
	int rootidx = ir[root];
	int lsz = rootidx - is;
	int rsz = sz - lsz - 1;

	post(ps + 1, is, lsz);
	post(ps + lsz + 1, rootidx + 1, rsz);
	printf("%d ", root);
}
int main()
{
	int t;
	for (scanf("%d", &t); t; --t) {
		scanf("%d", &n);
		for (int i = 0; i<n; ++i) {
			scanf("%d", &pre[i]);
			pr[pre[i]] = i;
		}
		for (int i = 0; i<n; ++i) {
			scanf("%d", &in[i]);
			ir[in[i]] = i;
		}
		post(0, 0, n);
		printf("\n");
	}
}
