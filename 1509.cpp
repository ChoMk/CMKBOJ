#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<iostream>

using namespace std;

string temp;
int dp[2511];


int fun(int idx) {
	
	int &reg = dp[idx];
	if (reg != -1)
		return reg;
	if (idx == temp.size())
		return 0;

	reg = 987654321;
	int cntA = 1;
	while (true) {
		if (cntA + idx > temp.size())
			break;
		int divCnt = cntA / 2;
		int sw = 0;
		for (int i = 0; i < divCnt; i++) {

			if (temp[idx + i] != temp[idx + cntA - i - 1])
			{
				sw = 1;
				break;
			}

		}
		cntA++;
		if (sw == 1)
		{
			continue;
		}
		reg = min(reg, fun(idx + cntA-1) + 1);
	}

	return reg;
}

int main() {
	
	cin >> temp;
	memset(dp, -1, sizeof(dp));
	int result = fun(0);
	cout << result << endl;

}