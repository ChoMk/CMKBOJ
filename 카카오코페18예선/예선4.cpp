#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;


int n;
int q;
int x, y;
int A, B;
int hp;
priority_queue<pair<int, pair<int, int>>>pq;
vector<pair<int, int>> nodeX;
vector<pair<int, int>> nodeY;
vector<pair<pair<int, pair<int, int>>,int>> query;


int parent[2500001];
bool answer[250001];

int ufind(int idx) {
	if (parent[idx] < 0)
		return idx;
	return parent[idx] = ufind(parent[idx]);
}

void uMerge(int a, int b) {
	a = ufind(a);//각각의 루트
	b = ufind(b);

	if (a == b)
		return;
	parent[a] = b;
}

int main() {
	memset(parent, -1, sizeof(parent));
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		nodeX.push_back({x, i});
		nodeY.push_back({ y, i});
	}
	sort(nodeX.begin(), nodeX.end());
	sort(nodeY.begin(), nodeY.end());
	for (int i = 0; i < n - 1; i++) {
		int dist = -abs(nodeX[i].first - nodeX[i + 1].first);
		
		pq.push({ dist, {nodeX[i].second, nodeX[i + 1].second} });
		dist = -abs(nodeY[i].first - nodeY[i + 1].first);

		pq.push({ dist,{ nodeY[i].second, nodeY[i + 1].second } });

	}

	for (int i = 0; i < q; i++) {
		scanf("%d %d %d", &A, &B, &hp);
		A--;
		B--;
		query.push_back({ { hp, {A,B} }, i});
	}
	sort(query.begin(), query.end());
	for (int i = 0; i < q; i++) {
		hp = query[i].first.first;
		A = query[i].first.second.first;
		B = query[i].first.second.second;

		while (!pq.empty()) {
			int currentHp = -pq.top().first;
			if (currentHp > hp)
				break;
			uMerge(pq.top().second.first, pq.top().second.second);
			pq.pop();
		}
		answer[query[i].second] = (ufind(A) == ufind(B));
	}
	for (int i = 0; i < q; i++) {
		if (answer[i])
			printf("YES\n");

		else
			printf("NO\n");
	}
}