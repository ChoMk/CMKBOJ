#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

int v, q, k;
vector<int> node[1001];
int a, b, c;
bool visit[1001];
int arr[1001][4];


int main() {
	scanf("%d %d %d", &v, &q, &k);
	for (int i = 0; i < v - 1; i++) {
		scanf("%d %d", &a, &b);
		node[a].push_back(b);
		node[b].push_back(a);
	}
	
	for (int i = 1; i <= v; i++) {
		scanf("%d %d %d", &arr[i][1], &arr[i][2], &arr[i][3]);
	}
	visit[1] = true;
}