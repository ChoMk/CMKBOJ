#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int n;
int k;
int arr[501];
double result = 987654321;

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = k; i <= n; i++) {
		for (int j = 0; j <= n-i; j++) {
			double tempResult = 0;
			double tempAV = 0;
			for (int L = j; L < j + i; L++) {
				tempAV += (double)arr[L];
			}//i(k)���� ����
			tempAV = tempAV / (double)i;
			for (int L = j; L < j + i; L++) {
				tempResult += ((double)arr[L] - tempAV)*((double)arr[L] - tempAV);
			}//i(k)���� ����
			tempResult /= (double)i;
			tempResult = sqrt(tempResult);
			result = min(result, tempResult);
		}

	}//������ �ּ� k������ n�� ���ð���
	printf("%.11lf\n", result);
}//500 + 250 + 160 + ...