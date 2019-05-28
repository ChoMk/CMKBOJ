#include<cstdio>
#include<algorithm>

using namespace std;
int a;
int temp10;
int temp1;

int main() {
	scanf("%d", &a);
	temp10 = a / 10;
	temp1 = a % 10;
	int result = 0;
	while (true) {
		int sumTemp = temp10 + temp1;
		temp10 = temp1;
		temp1 = sumTemp % 10;
		result++;
		if (a == temp10 * 10 + temp1)
			break;
	}
	printf("%d\n", result);
}