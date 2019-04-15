#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

string arr;
bool dp[1002][1002];


int main() {
	cin >> arr;
	for (int i = 0; i < arr.size(); i++) {
		dp[i][i] = true;
	}
	for (int i = 0; i < arr.size() - 1; i++) {
		if (arr[i] == arr[i + 1])
			dp[i][i + 1] = true;

	}
	for (int k = 2; k < arr.size(); k++) {
		for (int i = 0; i < arr.size() - k; i++) {
			int j = i + k;
			if (arr[i] == arr[j] && dp[i + 1][j - 1])
				dp[i][j] = true;
		}
	}
	int result = -1;
	for (int i = 0; i < arr.size(); i++) {
		if (dp[i][arr.size()-1])
			result = max(result, (int)arr.size() - i);
	}
	printf("%d\n", result + (arr.size() - result) * 2);

}