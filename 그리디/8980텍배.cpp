#include<cstdio>
#include<algorithm>
#include<vector>


using namespace std;
vector<pair<pair<int, int>, int>> node;
int n, m;
int k;
int posible[2002];
int a, b, c;
int result;

vector<pair<int, int>> carry;
int main() {
	scanf("%d %d", &n, &m);
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d %d", &a, &b, &c);
		node.push_back({{ b,a }, c});
	}
	sort(node.begin(), node.end());
	for (int i = 0; i < k; i++) {
		int preW = 0;
		for (int j = node[i].first.second; j < node[i].first.first; j++) {
			preW = max(posible[j], preW);
		}
		int currW = min(m - preW, node[i].second);
		result += currW;
		for (int j = node[i].first.second; j < node[i].first.first; j++) {
			posible[j] += currW;
		}
	}
	printf("%d\n", result);

}