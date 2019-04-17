#include<cstdio>
#include<algorithm>

using namespace std;
int t;
int a, b;
int main() {

	scanf("%d", &t);
	while (t--) {
		int sumPrice = 0;
		scanf("%d %d", &a, &b);
		if (a == 1) {
			sumPrice += 5000000;
		}
		else if (2<=a && a<4) {
			sumPrice += 3000000;
		}
		else if (4<=a&&a<7) {
			sumPrice += 2000000;
		}
		else if (7<=a&&a<11) {
			sumPrice += 500000;
		}
		else if (11<=a&&a<16) {
			sumPrice += 300000;
		}
		else if (16<=a&&a<22) {
			sumPrice += 100000;
		}
		if (b == 1) {
			sumPrice += 5120000;
		}
		else if (2 <= b && b<4) {
			sumPrice += 2560000;
		}
		else if (4 <= b && b<8) {
			sumPrice += 1280000;
		}
		else if (8 <= b && b<16) {
			sumPrice += 640000;
		}
		else if (16 <= b && b<32) {
			sumPrice += 320000;
		}

		printf("%d\n", sumPrice);
	}
}