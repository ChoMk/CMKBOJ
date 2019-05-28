#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

long long MOD = 1000000007;
int n;
vector<long long> temp;//하나 남을때 행렬
vector<long long> multiple(vector<long long> a, vector<long long> b) {
	vector<long long> result;
	result.push_back((a[0]*b[0]% MOD +a[1]*b[2] % MOD) % MOD);
	result.push_back((a[0] * b[1] % MOD + a[1] * b[3] % MOD) % MOD );
	result.push_back((a[2] * b[0] % MOD + a[3] * b[2] % MOD) % MOD);
	result.push_back((a[2] * b[1] % MOD + a[3] * b[3] % MOD) % MOD );
	return result;
}
vector<long long> fastMultiple(int currN) {
	if (currN == 1)
		return temp;
	vector<long long> result;
	if (currN % 2 == 1) {
		result = multiple(multiple(fastMultiple(currN / 2), fastMultiple(currN / 2)), temp);
	}
	else {

		result = multiple(fastMultiple(currN / 2), fastMultiple(currN / 2));
	}
	return result;
}//재귀로 짜면 겹침... 페스트하지 않음;;

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
	
	vector<long long> resultcon = fastMultiple(n);
	vector<long long> firstf;
	firstf.push_back(1);
	firstf.push_back(0);
	firstf.push_back(0);
	firstf.push_back(0);
	vector<long long> R = multiple(firstf, resultcon);
	printf("%lld\n", R[1]);
}