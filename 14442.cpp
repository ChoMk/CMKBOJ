#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;


int n, m, k;
char arr[1001][1001];
int visit[1001][1001][11];

int cont[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
queue<pair<pair<int, int>,int>> q;
void fun() {

	q.push(make_pair(make_pair(0, 0),k));
	
	while (true) {
		if (q.size() == 0)
		{
			return;
		}
		int presentY = q.front().first.first;
		int presentX = q.front().first.second;
		int presentK = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextY = presentY + cont[i][0];
			int nextX = presentX + cont[i][1];
			if (nextY >= n || nextX >= m || nextY < 0 || nextX < 0)
				continue;
			if (arr[nextY][nextX] == '1')
			{
				if (presentK - 1 >= 0)
				{
					if (visit[nextY][nextX][presentK - 1] == -1)
					{
						visit[nextY][nextX][presentK-1]=visit[presentY][presentX][presentK] + 1;
						q.push(make_pair(make_pair(nextY, nextX), presentK - 1));
						
					}
					/*else {
						visit[nextY][nextX][presentK - 1] = min(visit[presentY][presentX][presentK] + 1, visit[nextY][nextX][presentK - 1]);

					}*/
				}
			}
			else {
				if (visit[nextY][nextX][presentK] == -1)
				{
					visit[nextY][nextX][presentK] = visit[presentY][presentX][presentK] + 1;
					q.push(make_pair(make_pair(nextY, nextX), presentK));
				}
				/*else {
					visit[nextY][nextX][presentK] = min(visit[presentY][presentX][presentK] + 1, visit[nextY][nextX][presentK]);

				}*/
			}
			

		}
	}

	return;

}



int main()
{
	scanf("%d %d %d", &n, &m, &k);
	cin.ignore();
	memset(visit, -1, sizeof(visit));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%c", &arr[i][j]);
		}
		cin.ignore();
	}
	visit[0][0][k] = 1;
	fun();
		int result = 987654321;
		for (int i = 0; i <= k; i++) {
			if (visit[n - 1][m - 1][i] == -1)
				continue;
			result = min(result, visit[n - 1][m - 1][i]);
		}
		if (result == 987654321)
		{
			printf("-1\n");
		}
		else {
			printf("%d\n", result);

		}
		

}