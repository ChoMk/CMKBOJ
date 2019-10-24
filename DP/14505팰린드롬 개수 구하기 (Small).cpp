#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>

using namespace std;

long long dp[31][31];
string arr;

long long fun(int startIDX, int endIDX) {

	if (startIDX == endIDX)
		return 1;
	if (startIDX > endIDX)
		return 0;
	long long &reg = dp[startIDX][endIDX];
	if (reg != -1)
		return reg;
	
	reg = 0;
	long long temp = fun(startIDX + 1, endIDX) + fun(startIDX, endIDX - 1) - fun(startIDX + 1, endIDX - 1);
	if (arr[startIDX] == arr[endIDX]) {
		reg += fun(startIDX + 1, endIDX - 1) + 1;
	}
	return reg += temp;

}

int main() {
	cin >> arr;
	memset(dp, -1, sizeof(dp));
	cout << fun(0, arr.size() - 1)<<"\n";
}