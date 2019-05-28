#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
int checkD[10001];
int minR;
int result;
int main() {
	for (int i = 1; i <= 10000; i++) {
		if(i*i<=10000)
			checkD[i*i]++;
	}
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = n; i <= m; i++) {
		if (checkD[i] == 1) {
			if (minR == 0)
				minR = i;
			result += i;
		}
	}
	if (result == 0) {
		printf("-1\n");

	}
	else {
		printf("%d\n%d\n", result, minR);
	}
}