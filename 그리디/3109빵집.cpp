#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string>

using namespace std;
int x, y;
char table[10001][501];
bool visit[10001][501];
int d[4][2] = { {-1, 1}, {0, 1}, {1, 1} };

bool dfs(int curx, int cury) {
	visit[curx][cury] = true;
	if (cury == y-1)
		return true;
	for (int i = 0; i < 3; i++) {
		int nextx = curx + d[i][0];
		int nexty = cury + d[i][1];
		if (nextx > -1 && nextx < x && !visit[nextx][nexty] && table[nextx][nexty] == '.') {
			if (dfs(nextx, nexty)	)
				return true;
		}
	}
	return false;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> x >> y;
	for (int i = 0; i < x; i++) {
		cin.ignore();
		for (int j = 0; j < y; j++) {
			cin >> table[i][j];
		}
	}
	int result = 0;
	for (int i = 0; i < x; i++) {
		
		if (dfs(i, 0))
			result++;
	}
	cout << result << "\n";

}