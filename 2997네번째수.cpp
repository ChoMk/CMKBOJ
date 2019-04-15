#include<cstdio>
#include<algorithm>

using namespace std;

int a[4];
int result;

int main() {
	scanf("%d %d %d", &a[0], &a[1], &a[2]);
	sort(a, a + 3);
	int dist1 = a[1] - a[0];
	int dist2 = a[2] - a[1];

	if (dist1 == dist2) {
		printf("%d\n", a[2] + dist2);
	}
	else {
		int mindist = min(abs(dist1), abs(dist2));
		if (mindist == abs(dist1)) {
			printf("%d\n", a[1] + dist1);
		}
		else {
			printf("%d\n", a[1] - dist2);
		}
	}
}