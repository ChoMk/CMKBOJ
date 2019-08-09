#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<iostream>


using namespace std;


int startLeft, startRight;
string arr;
int dp[51][51];
int result = 987654321;
bool state;
int fun(int left, int right) {
	if (left == right)
		return 0;
	if (right - left == 1 && arr[right] == arr[left]) {
		return 0;
	}
	if(left>right)
		return 987654321;
	int &reg = dp[left][right];
	if (reg != -1) {
		return reg;
	}
	reg = 987654321;
	if (arr[left] == arr[right]) {
		reg = fun(left + 1, right - 1);
	}
	else {
		reg = fun(left + 1, right - 1)+1;
	}
	return reg = min(min(reg, fun(left + 1, right) + 1), fun(left, right - 1) + 1);
}

int main() {
	cin >> arr;

	memset(dp, -1, sizeof(dp));
	result = fun(0, arr.size()-1);
	for (int i = 0; i < arr.size(); i++) {
		for (int j = i + 1; j < arr.size(); j++) {
			swap(arr[i], arr[j]);
			memset(dp, -1, sizeof(dp));

			result = min(result, fun(0, arr.size() - 1)+1);
			swap(arr[i], arr[j]);
		}
	}
	cout << result << "\n";

}