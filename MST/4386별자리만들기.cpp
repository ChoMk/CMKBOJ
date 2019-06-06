#include<cstdio>
#include<algorithm>
#include<iostream>
#include<queue>

using namespace std;

int n;

double table[101][101];
double arr[101][2];
bool visit[101];
double result;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1];
		 
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			table[i][j] = (double)sqrt(((arr[i][0] - arr[j][0])*(arr[i][0] - arr[j][0]) + (arr[i][1] - arr[j][1])*(arr[i][1] - arr[j][1])));
		}
	}
	priority_queue<pair<double, int>> pq;
	pq.push({ 0.0, 0 });
	while (true) {
		if (pq.empty())
			break;
		int curr = pq.top().second;
		double dist = -pq.top().first;
		pq.pop();
		if (visit[curr]) {
			continue;
		}
		visit[curr] = true;
		result += dist;
		for (int i = 0; i < n; i++) {
			int nextIDX = i;
			double nextCost = table[curr][nextIDX];
			if (!visit[nextIDX])
				pq.push({ -nextCost, nextIDX });
		}
	}
	cout << result << "\n";
}
