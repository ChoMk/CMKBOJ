#include<cstdio>
#include<algorithm>

using namespace std;

int sx, sy;
int lx, ly;
int a, b;
int n;

int main() {
	sx = 987654321;
	sy = 987654321;
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		sx = min(a, sx);
		sy = min(b, sy);
		lx = max(a, lx);
		ly = max(b, ly);

	}
	printf("%d\n", max(abs(sx - lx), abs(sy - ly))*max(abs(sx - lx), abs(sy - ly)));



}