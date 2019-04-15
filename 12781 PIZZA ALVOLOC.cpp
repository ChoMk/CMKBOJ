#include<cstdio>
#include<algorithm>

using namespace std;

int u1, v1;
int u2, v2;
int u3, v3;
int u4, v4;


int main() {
	scanf("%d %d", &u1, &v1);
	scanf("%d %d", &u2, &v2);
	scanf("%d %d", &u3, &v3);
	scanf("%d %d", &u4, &v4);

	int result1 = u1 * v3 + u3 * v2 + u2 * v1 - u3 * v1 - u2 * v3 - u1 * v2;
	int result2 = u1 * v4 + u4 * v2 + u2 * v1 - u4 * v1 - u2 * v4 - u1 * v2;
	if ((result1 <0&&result2>0)|| (result1 >0 && result2<0)) {
		printf("1\n");
	}
	else {
		printf("0\n");
	}


}