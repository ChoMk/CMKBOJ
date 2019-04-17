#include<cstdio>
#include<algorithm>
using namespace std;

int n;
int arr[2289][2289];
int result[3];
int fun(int hs, int he, int ws, int we) {
	if (he-hs == 1) {
		return arr[hs][ws];
	}
	int hDis = (he - hs)/3;
	int wDis = (we - ws) / 3;

	int temp[9];
	
	temp[0] = fun(hs, hs+hDis, ws, ws+wDis);
	
	temp[1] = fun(hs+hDis, hs+hDis*2, ws, ws+wDis);
	
	temp[2] = fun(hs+hDis*2, he, ws, ws+wDis);
	
	temp[3] = fun(hs, hs+hDis, ws+wDis, ws+2*wDis);
	
	temp[4] = fun(hs, hs+hDis, ws+wDis*2, we);
	
	temp[5] = fun(hs + hDis, hs + hDis * 2, ws + wDis, ws + 2 * wDis);
	
	temp[6] = fun(hs + hDis * 2, he, ws + wDis * 2, we);
	
	temp[7] = fun(hs + hDis, hs + hDis * 2, ws + wDis * 2, we);
	
	temp[8] = fun(hs + hDis * 2, he, ws + wDis, ws + 2 * wDis);
	

	bool checkFlag = true;
	int comp = temp[0];
	if (temp[0] != -2) {
		for (int i = 1; i < 9; i++) {
			if (temp[i] != comp) {
				checkFlag = false;
				break;
			}
		}
	}
	else {
		checkFlag = false;
	}
	

	if (checkFlag) {
		return temp[0];
	}
	else {
		for (int i = 0; i < 9; i++) {
			if (temp[i]!= -2) {
				result[temp[i] + 1]++;
			}//Ä«¿îÆ®
		}
		
		return -2;
	}



}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	if (n == 1) {
		result[arr[0][0] + 1]++;
		for (int i = 0; i < 3; i++) {
			printf("%d\n", result[i]);
		}
	}
	else {
		int resultVal = fun(0, n, 0, n);
		if (resultVal != -2) {
			result[arr[0][0] + 1]++;

			for (int i = 0; i < 3; i++) {
				printf("%d\n", result[i]);
			}
		}
		else {
			for (int i = 0; i < 3; i++) {
				printf("%d\n", result[i]);
			}
		}
		
	}
	
}