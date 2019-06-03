#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;
long long n;
long long t;
long long a, b;
vector<long long> s;
vector<long long> d;
long long result;
int main() {
	scanf("%lld %lld", &n, &t);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &a, &b);
		s.push_back(b);
		d.push_back(a);
	}
	long long currSpeed = s[n - 1];
	long long currIDX = d[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		if (abs(currIDX - d[i]) + currSpeed * t - s[i] * t > 0) {
			result++;
			currIDX = d[i];
			currSpeed = s[i];
		}
		
	}
	printf("%lld\n", result + 1);
}