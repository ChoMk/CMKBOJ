#include<cstdio>
#include<algorithm>

using namespace std;
int n, r, c;
int recD;
int cnt;
int cont[4][2] = { {0,0}, {0,1},{1,0},{1,1} };
void fun(int curn, int curr, int curc) {
	if (curn == 2) {
		for (int i = 0; i < 4; i++) {
			int nextr = curr + cont[i][0];
			int nextc = curc + cont[i][1];
			if (nextr == r && nextc == c) {
				printf("%d\n", cnt);
				return;
			}
			cnt++;

		}
		return;
	}
	fun(curn / 2, curr, curc);
	fun(curn / 2, curr, curc+curn/2);
	fun(curn / 2, curr + curn / 2, curc);
	fun(curn / 2, curr + curn / 2, curc + curn / 2);


}


int main() {
	scanf("%d %d %d", &n, &r, &c);
	recD = 1 << n;
	fun(recD, 0, 0);
}