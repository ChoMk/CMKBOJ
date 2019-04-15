#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n;
vector<pair<long long, long long>> savePoint;
long long tempx, tempy;
double result;


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &tempx, &tempy);
		savePoint.push_back({ tempx, tempy });
	}
	//u1 * v2 + u2 * v3 + u3 * v1 - u2 * v1 - u3 * v2 - u1 * v3;
	for (int i = 0; i < n - 2; i++) {
		result += (savePoint[0].first * savePoint[i+1].second + savePoint[i+1].first * savePoint[i+2].second + savePoint[i+2].first*savePoint[0].second
		-savePoint[i+1].first * savePoint[0].second - savePoint[i+2].first*savePoint[i+1].second - savePoint[0].first*savePoint[i+2].second)/2.0;
	}
	printf("%.1lf\n", abs(result));
}