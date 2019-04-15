#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int n;
long long x[110001];
long long y[110001];
long long result;
vector<pair<long long, long long>> arr;
long long a;
long long b;


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &a, &b);
		x[a]++;
		y[b]++;
		arr.push_back({ a,b });
	}
	for (int i = 0; i < n; i++) {
		int curx = arr[i].first;
		int cury = arr[i].second;
		result += (x[curx] - 1)*(y[cury] - 1);
		
	}
	printf("%lld\n", result);
}