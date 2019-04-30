#include<cstdio>
#include<algorithm>

using namespace std;

bool boxS[4] = { false, true, false, false };

int m;
int a, b;
int main() {
	scanf("%d", &m);
	while (m--) {
		scanf("%d %d", &a, &b);
		swap(boxS[a], boxS[b]);
	}
	for (int i = 1; i <= 3; i++) {
		if (boxS[i] == true) {
			printf("%d\n", i);
		}
	}
}