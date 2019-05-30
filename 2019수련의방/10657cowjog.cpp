#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;
long long n;
long long a,b;
vector<long long> s;
long long result;
int main() {
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &a, &b);
		s.push_back(b);
	}
	long long currSpeed = s[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		if (!(currSpeed < s[i])) {

			result++;
		}
		currSpeed = min(currSpeed, s[i]);
	}
	printf("%lld\n", result++);
}