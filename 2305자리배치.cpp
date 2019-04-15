#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
int n;
int k;
int dp[42][2][2][2];//현 위치 자신, 자신 왼쪽 비었는지
int fun(int idx, int letfEmpty, int midEmpty, int kEmpty) {
	if (idx == n + 1)
		return 1;
	int &reg = dp[idx][letfEmpty][midEmpty][kEmpty];
	if (reg != -1)
		return reg;
	reg = 0;
	int nextIDX = idx + 1;
	
	if (idx == k) {
		return reg = fun(nextIDX, kEmpty, 0, kEmpty);
		
	}
	else {
		if (idx != n && idx +1 != k) {//마지막에는 오른쪽 못채움, k는 k상태를 보고 뒤에서 수행
			
			reg += fun(nextIDX, midEmpty, 1, kEmpty);//오른쪽 채움
		}
				
		
		if (letfEmpty == 0 && idx-1 != k) {//k는 k상태를 보고 뒤에서 수행
			
			reg += fun(nextIDX, midEmpty, 0, kEmpty);//왼쪽 채움

		
			
		}
		if (midEmpty == 0) {//미드가 k가 생기는 경우는 없음
			
			reg += fun(nextIDX, 1, 0, kEmpty);//미드채움
			
			
		}
		if (kEmpty == 0) {
			
			reg += fun(nextIDX, midEmpty, 0, 1);//k채움
			
			
		}
	}
	
	return reg;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	scanf("%d", &k);
	printf("%d\n", fun(1, 1, 0, 0));//0 = 자기위치, 1 = 왼쪽, 2 = 중간, 3 = 자유석
	
}