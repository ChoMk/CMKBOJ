#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
int n, m;
int A[51][51];
int B[51][51];


void changeM(int x, int y) {
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			A[i][j] = (A[i][j] + 1) % 2;
		}
	}
}

int main() {
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++) {
			
			A[i][j] = temp[j] - '0';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char temp;
			cin >> temp;
			B[i][j] = temp - '0';
		}
	}
	int resultCnt = 0;
	for (int i = 0; i <= n - 3; i++) {
		for (int j = 0; j <= m - 3; j++) {
			if (A[i][j] != B[i][j]) {
				resultCnt++;
				changeM(i, j);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (A[i][j] != B[i][j]) {
				cout << -1 << "\n";
				return 0;
			}
		}
	}
	cout << resultCnt << "\n";
}