#include<cstdio>
#include<algorithm>

using namespace std;

int n, m, k;
int result;
int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i <= k; i++) {
		int restn = n - i;
		int restm = m - (k - i);
		if (restn < 2)
			break;
		if (restm < 1)
			continue;
		result = max(result, min(restn / 2, restm));


	}
	printf("%d\n", result);
}