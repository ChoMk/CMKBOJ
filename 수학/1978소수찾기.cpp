#include<cstdio>
#include<algorithm>

using namespace std;

int n;
int checkP[1001];
int result;
int a;
int main() {
	for (int i = 2; i < 1001; i++) {
		if (checkP[i] != 0) {
			checkP[i]++;
			continue;
		}
			
		for (int j = 1; j < 1001; j++) {
			if (i*j > 1000)
				break;
			checkP[i*j]++;
		}
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (checkP[a] == 1)
			result++;
	}
	printf("%d\n", result);
}