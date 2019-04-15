#include<cstdio>
#include<algorithm>

using namespace std;

int arr[10];
int result;

int main() {
	for (int i = 0; i < 6; i++) {
		scanf("%d", &arr[i + 1]);
	}
	result += arr[6];


	result += arr[5];
	arr[1] -= arr[5] * 11;

	result += arr[4];
	int restSq2 = arr[4] * 5;
	int restSq1 = restSq2 * 4;
	if (arr[2] >= restSq2) {
		arr[2] -= restSq2;
		restSq1 -= restSq2 * 4;
	}
	else {
		restSq1 -= arr[2] * 4;
		arr[2] = 0;
	}

	arr[1] -= restSq1;


	if (arr[2] < 0)
		arr[2] = 0;
	if (arr[1] < 0)
		arr[1] = 0;

	result += arr[3] / 4;
	if (arr[3] % 4 > 0) {
		result++;
		if (arr[3] % 4 == 1) {
			if (arr[2] >= 5) {
				arr[1] -= 7;
				arr[2] -= 5;
			}
			else {
				arr[1] -= (5-arr[2]) * 4 + 7;
				arr[2] = 0;
			}
			
		}
		else if (arr[3] % 4 == 2) {
			
			if (arr[2] >= 3) {
				arr[2] -= 3;
				arr[1] -= 6;
			}
			else {
				arr[1] -= (3-arr[2]) * 4 + 6;
				arr[2] = 0;
			}
		}
		else {
			if (arr[2] >= 1) {

				arr[1] -= 5;
				arr[2] -= 1;
			}
			else {
				arr[1] -= (1-arr[2]) * 4 + 5;
				arr[2] = 0;
			}
		}
	}

	if (arr[2] < 0)
		arr[2] = 0;
	if (arr[1] < 0)
		arr[1] = 0;


	if (arr[2] > 0) {
		result += arr[2] / 9;
		if (arr[2] % 9 > 0) {
			result++;
			restSq1 = (9 - arr[2] % 9) * 4;
			arr[1] -= restSq1;

		}
	}
	if (arr[2] < 0)
		arr[2] = 0;
	if (arr[1] < 0)
		arr[1] = 0;

	if (arr[1] > 0) {
		result += arr[1] / 36;
		if (arr[1] % 36 > 0) {
			result++;
		}
	}
	printf("%d\n", result);

}