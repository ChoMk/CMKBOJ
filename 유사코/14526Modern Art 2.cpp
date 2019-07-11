#include<algorithm>
#include<cstring>
#include<vector>
#include<cstdio>

using namespace std;

int c[100003];
int cmin[100003];
int cmax[100003];

int n;

vector<int> stack;
int result;

int main() {
	scanf("%d", &n);
	fill(cmin, cmin + 100003, 987654321);
	fill(cmax, cmax + 100003, -987654321);

	c[0] = 0;
	c[n + 1] = 0;
	cmin[0] = 0;
	cmax[0] = n + 1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
		cmin[c[i]] = min(cmin[c[i]], i);
		cmax[c[i]] = max(cmax[c[i]], i);
	}
	for (int i = 0; i <= n+1; i++) {
		int tempc = c[i];
		if (i == cmin[tempc]) {
			stack.push_back(tempc);
			result = max(result, (int)stack.size());
		}
		if (stack[stack.size() - 1] != tempc) {
			printf("-1\n");
			return 0;
		}
		if(i == cmax[tempc]){
			stack.pop_back();
		}
	}
	printf("%d\n", result-1);

}