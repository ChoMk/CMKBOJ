#include<algorithm>
#include<cstdio>

using namespace std;

int n;
long long arrA[500001];
long long arrB[500001];


int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arrA[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arrB[i]);
	}
	for (int i = 0; i < n-1; i++) {
		printf("%d ", upper_bound(arrB + i + 1, arrB + n, arrA[i]) - arrB-i-1);
	}
	printf("0\n");
}