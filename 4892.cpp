#include<cstdio>
#include<algorithm>

using namespace std;
int n;
int cnt = 1;

int main()
{
	while (true) {
		scanf("%d", &n);
		if (n == 0)
			break;
		int n1 = n * 3;
		if (n1 % 2 == 0)
		{
			int n2 = n1 / 2;
			int n3 = n2 * 3;
			int n4 = n3 / 9;
			printf("%d. even %d\n", cnt, n4);
		}
		else {
			int n2 = (n1+1) / 2;
			int n3 = n2 * 3;
			int n4 = n3 / 9;
			printf("%d. odd %d\n", cnt, n4);

		}
		cnt++;

	}
	
}