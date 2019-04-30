#include<cstdio>
#include<algorithm>

using namespace std;

int startIDX;
int n;
int T;
char state;
int maxT = 210;
int curT;

int main() {
	scanf("%d", &startIDX);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %c", &T, &state);
		if (state == 'T') {
			curT += T;
			if (maxT <= curT) {
				printf("%d\n", startIDX);
				break;
			}
			startIDX++;
			if (startIDX > 8)
				startIDX = 1;
		}
		else {
			curT += T;
			if (maxT <= curT) {
				printf("%d\n", startIDX);
				break;
			}
		}
		
		
	}
}