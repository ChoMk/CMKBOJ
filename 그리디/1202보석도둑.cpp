#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n, k;
vector<pair<long long, long long>>d;
vector<long long>b;
long long x, y;
int checkd[300001];
long long result;
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &x, &y);
		d.push_back({ x,y });
	}
	sort(d.begin(), d.end());
	for (int i = 0; i < k; i++) {
		scanf("%lld", &x);
		b.push_back(x);
	}
	priority_queue<long long>pq;

	sort(b.begin(), b.end());
	int preJ = 0;
	for (int i = 0; i < b.size(); i++) {
		for (int j = preJ; j < d.size(); j++) {
			if (b[i] >= d[j].first) {
				pq.push(d[j].second);
				preJ = j+1;
			}
			else {
				preJ = j;
				break;
			}
		}
		if (!pq.empty()) {
			result += pq.top();
			pq.pop();
		}
		
	}
	printf("%lld\n", result);
}