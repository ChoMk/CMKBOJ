#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

int n;
int arr[65][65];
string fun(int wS, int wE, int hS, int hE) {
	
	if (wE == wS)
		return"";
	if (wE - wS == 1) {
		if (arr[hS][wS] == arr[hS][wS + 1] && arr[hS][wS + 1] == arr[hS + 1][wS] && arr[hS + 1][wS] == arr[hS + 1][wS + 1] && arr[hS + 1][wS + 1] == arr[hS][wS]) {
			return to_string(arr[hS][wS]);
		}
		else {
			return "("+ to_string(arr[hS][wS])+ to_string(arr[hS][wS+1])+ to_string(arr[hS+1][wS])+ to_string(arr[hS+1][wS+1]) +")";

		}
	}
	
	string temp1 = fun(wS, (wS+wE) / 2, hS, (hE+hS) / 2);
	string temp2 = fun((wE+wS) / 2 + 1, wE, hS, (hE+hS) / 2);
	string temp3 = fun(wS, (wE+wS) / 2, (hE+hS) / 2 + 1, hE);
	string temp4 = fun((wE+wS) / 2 + 1, wE, (hE+hS) / 2 + 1, hE);
	if (temp1.size() == 1 && temp1 == temp2 && temp2 == temp3 && temp3 == temp4 && temp4 == temp1) {
		return temp1;
	}
	else {
		return "(" + temp1 + temp2 + temp3 + temp4 + ")";
	}
	
}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	cout << fun(0, n-1, 0, n-1) << "\n";
}
