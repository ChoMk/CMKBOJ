#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
int n, m, k;
int dp[101][101];
string result;
bool checkPossibleFlag = true;

int countAZ(int a, int z) {
	int &reg = dp[a][z];
	if (a == 0 || z == 0)
		return reg = 1;
	if (reg != -1)
		return reg;
	reg = min(1000000001, countAZ(a - 1, z) + countAZ(a, z - 1));
	return reg;
}

void makeStringAZ(int a, int z, int sk) {
	if (a == 0) {
		for (int i = 0; i < z; i++) {
			result += 'z';
		}
		return;
	}
	if (z == 0) {
		for (int i = 0; i < a; i++) {
			result += 'a';
		}
		return;
	}
	int checkCnt = countAZ(a - 1, z);
	if (sk < checkCnt) {
		result += 'a';
		makeStringAZ(a - 1, z, sk);
	}
	else{
		result += 'z';
		makeStringAZ(a, z - 1, sk-checkCnt);
	}

}



int main() {
	scanf("%d %d %d", &n, &m, &k);
	memset(dp, -1, sizeof(dp));


	if (k > countAZ(n, m)) {
		printf("-1\n");
		return 0;
	}

	makeStringAZ(n, m, k - 1);
	cout << result << "\n";
	return 0;




}