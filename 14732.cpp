#include<cstdio>
#include<algorithm>

using namespace std;


int n;
int arr[501][501];
int a, b, c, d;
int result = 0;




int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		for (int i = a; i < c; i++) {
			for (int j = b; j < d; j++) {
				arr[i][j]++;
			}
		}

	}
	for (int i = 0; i <= 500; i++) {
		for (int j = 0; j <= 500; j++) {
			if (arr[i][j] != 0)
				result++;
		}
	}
	printf("%d\n", result);

}