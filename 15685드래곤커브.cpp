#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;


bool temp[101][101];
int n;
int x, y, d, g;
long long resultG[101];
vector<pair<int, int>> saveD;

int resultCnt() {
	int cnt = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (temp[i][j] == true && temp[i + 1][j] == true && temp[i][j + 1] == true && temp[i + 1][j + 1] == true)
				cnt++;
		}
	}
	return cnt;
}
void fun(int pG) {

	
	if (pG == g) {
		return;
	}
	int sX = saveD[saveD.size()-1].first;
	int sY = saveD[saveD.size() - 1].second;
	temp[sX][sY] = true;
	int sizeD = saveD.size();
	for (int i = 1; i < sizeD; i++) {
		int px = saveD[sizeD-1-i].first;
		int py = saveD[sizeD - 1-i].second;

		int distX = (-px + sX);
		int distY = (-py + sY);

		int nextX = sX + distY;
		int nextY = sY  - distX;
		
		temp[nextX][nextY] = true;
		saveD.push_back({ nextX, nextY });
	}
	fun(pG + 1);

}



int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &x, &y, &d, &g);
		saveD.push_back({ x,y });
		int nextX;
		int nextY;
		if (d == 0) {
			nextX = x + 1;
			nextY = y;
		}
		else if (d == 1) {
			nextX = x;
			nextY = y - 1;
		}
		else if (d == 2) {
			nextX = x - 1;
			nextY = y;
		}
		else if (d == 3) {
			nextX = x;
			nextY = y + 1;
		}
		temp[x][y] = true;
		temp[nextX][nextY] = true;
		saveD.push_back({ nextX, nextY });
		fun(0);
		saveD.clear();
	}
	printf("%d\n", resultCnt());
}