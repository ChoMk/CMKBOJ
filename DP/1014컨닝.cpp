#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
#include<iostream>

using namespace std;

int t;
int n, m;
string temp;
int arr[13];
int dp[13][1<<11];

int makeNextBit(int nextLayer, int subBit) {
	int nextBitState = arr[nextLayer];
	int curBitLoc = 0;
	while (true) {
		if (subBit == 0)
			break;
		if (subBit % 2 == 1) {
			if (curBitLoc == 0) {
				nextBitState &= ~(1 << 1);
			}
			else if (curBitLoc == m-1) {
				nextBitState &= ~(1 << (m-2));
			}
			else {
				nextBitState &= ~(1 << curBitLoc - 1);
				nextBitState &= ~(1 << curBitLoc + 1);

			}
		}

		subBit /= 2;
		curBitLoc++;
	}
	return nextBitState;
}

int fun(int curlayer, int curbitstate) {
	if (curlayer == n)
		return 0;
	int &reg = dp[curlayer][curbitstate];
	if (reg != -1)
		return reg;
	
	reg = 0;
	for (int i = 0; i < (1 << m); i++) {
		if ((curbitstate & i) == i) {
			//
			int subbit = curbitstate & ~i;
			bool ableflag = true;
			int subbitcnt = 0;
			int tempBit = subbit;
			int preBit = 0;
			while (true) {
				if (tempBit == 0)
					break;
				if (tempBit % 2 == 1) {
					if (preBit == 1) {
						ableflag = false;
					}
					preBit = 1;
					subbitcnt++;
				}
				else {
					preBit = 0;
				}
				tempBit /= 2;
			}
			
			if (ableflag) {
				reg = max(reg, fun(curlayer + 1, makeNextBit(curlayer + 1, subbit)) + subbitcnt);
			}
		}//i´Â ²¨Áø »óÅÂ
	}
	return reg;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		memset(dp, -1, sizeof(dp));
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			int statebit = (1 << m)-1;
			cin >> temp;
			for (int j = 0; j < m; j++) {
				if (temp[j] == 'x') {
					statebit &= (~(1 << j));//ºñÆ®²ô±â
				}
			}
			arr[i] = statebit;
		}
		cout << fun(0, arr[0])<<"\n";
		


	}
}