#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

int n;
int dp[105][11][11][11];
int stringStart[101];
int stringEnd[101];
int convert(int x) {
	if (x < 0)return (10 - ((-x) % 10)) % 10;
	else return x % 10;
}
int fun(int currentIDX, int subVal1, int subVal2, int subVal3) {
	if (currentIDX == n)
		return 0;
	int &reg = dp[currentIDX][subVal1][subVal2][subVal3];
	if (reg != -1)
		return reg;
	reg = 987654321;
	if (convert(stringStart[currentIDX] + subVal1) == stringEnd[currentIDX]) {
		reg = fun(currentIDX + 1, subVal2, subVal3, 0);
	}
	for (int i = -3; i <= 3; i++) {
		if (i == 0)
			continue;
		int nextSub1 = convert(subVal1 + i);
		int nextSub2 = convert(subVal2 + i);
		int nextSub3 = convert(subVal3 + i);
		reg = min(reg, fun(currentIDX, nextSub1, subVal2, subVal3)+1);
		reg = min(reg, fun(currentIDX, nextSub1, nextSub2, subVal3)+1);
		reg = min(reg, fun(currentIDX, nextSub1, nextSub2, nextSub3)+1);


	}
	return reg;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%1d", &stringStart[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%1d", &stringEnd[i]);
	}
	printf("%d\n", fun(0, 0, 0, 0));

}