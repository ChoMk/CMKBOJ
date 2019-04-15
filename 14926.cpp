#include <cstdio>

int main() {
	int N;
	scanf("%d", &N);
	N++;
	int **edges = new int*[N];
	bool **visited = new bool*[N];
	for (int i = 0; i < N; i++) edges[i] = new int[N], visited[i] = new bool[N];

	int currentVertex = 0, preVertex = 0;

	int forLoopCount = (N - 1) * (N - 2) / 2;
	visited[1][N - 1] = visited[N - 1][1] = true;
	while (forLoopCount--) {
		for (int i = 1; i < N; i++) {
			if (i == currentVertex || visited[currentVertex][i]) continue;
			visited[currentVertex][i] = visited[i][currentVertex] = true;
			currentVertex = i;
			break;
		}
		printf("a%d ", currentVertex);
	}
	printf("a1");
}