#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

long long MOD = 1000000007;
int n;
vector<long long> temp;//하나 남을때 행렬
vector<long long> multiple(vector<long long> a, vector<long long> b) {
	vector<long long> result;
	result.push_back(((a[0] * b[0]) % MOD + (a[1] * b[2]) % MOD) % MOD);
	result.push_back(((a[0] * b[1]) % MOD + (a[1] * b[3]) % MOD) % MOD);
	result.push_back(((a[2] * b[0]) % MOD + (a[3] * b[2]) % MOD) % MOD);
	result.push_back(((a[2] * b[1]) % MOD + (a[3] * b[3]) % MOD) % MOD);
	return result;
}


int main() {
	temp.push_back(1);
	temp.push_back(1);
	temp.push_back(1);
	temp.push_back(0);
	scanf("%d", &n);
	if (n == 0) {
		printf("0\n");
		return 0;
	}
	else if (n == 1) {
		printf("1\n");
		return 0;
	}

	
	vector<long long> ans;
	ans.push_back(1);
	ans.push_back(0);
	ans.push_back(0);
	ans.push_back(1);
	while (n > 0) {
		if (n % 2 == 1) {
			ans = multiple(ans, temp);
		}
		temp = multiple(temp, temp);
		n /= 2;
	}
	printf("%lld\n", ans[1]);
}