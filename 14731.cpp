#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int n;
long long c, k;
long long MOD = 1000000007;
long long result;
int main() {
	scanf("%d", &n);
	
	while (n--) {
		scanf("%lld %lld", &c, &k);
		
		long long temp = 1;
		long long presentD = 2;
		long long presentK = k-1;

		while (true) {
			if (presentK == 0)
				break;

			if (presentK % 2 == 1) {
				temp *= presentD;
				temp %= MOD;
			}
			
			presentD = (presentD * presentD)%MOD;
			presentK /= 2;

		}
		if (k != 0)
			result = (result + ((c * k)%MOD*temp)%MOD) % MOD;
		
	}
	printf("%lld\n", result);

}