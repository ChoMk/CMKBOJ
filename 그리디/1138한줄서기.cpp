#include<cstdio>
#include<algorithm>
using namespace std;

int n;
int a;
int result[11];


int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		int cnt = 0;
		int idx = 0;
		while (true) {
			if (result[idx] != 0) {
				idx++;
				continue;

			}
			if (cnt == a)
				break;
			idx++;
			cnt++;

		}
		result[idx] = i;
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", result[i]);
	}
	printf("\n");
}