#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;


int table[4][4] = { {0, 2, 0, 1},
					{2, 1, 3, 0},
					{0, 3, 2, 1},
					{1, 0, 1, 3} };
int n;
int arr[1000001];
char DNA;

int fun(int idx, int preState) {
	if (idx == -1)
		return preState;
	return fun(idx - 1, table[preState][arr[idx]]);
}

int result;
int main() {
	scanf("%d", &n);
	
	cin.ignore();
	
	for (int i = 0; i < n; i++) {
		scanf("%c", &DNA);

		if (DNA == 'A') {
			arr[i] = 0;
		}
		else if (DNA == 'G') {
			arr[i] = 1;
		}
		else if (DNA == 'C') {
			arr[i] = 2;
		}
		else {
			arr[i] = 3;
		}
	}
	if (n == 1) {
		result = arr[0];
	}
	else {
		result = fun(n-2, arr[n-1]);
	}
	
	
	if (result == 0) {
		printf("A\n");
	}
	else if (result == 1) {
		printf("G\n");
	}
	else if (result == 2) {
		printf("C\n");

	}
	else {
		printf("T\n");
	}
}