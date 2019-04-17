#include<cstdio>
#include<algorithm>

using namespace std;

int u1, v1;
int u2, v2;
int u3, v3;

int main() {
	scanf("%d %d", &u1, &v1);
	scanf("%d %d", &u2, &v2);
	scanf("%d %d", &u3, &v3);

	int result = u1 * v2 + u2 * v3 + u3 * v1 - u2 * v1 - u3 * v2 - u1 * v3;
	if (result == 0) {
		printf("0\n");

	}
	else if (result < 0) {
		printf("-1\n");
	}
	else {
		printf("1\n");
	}
}