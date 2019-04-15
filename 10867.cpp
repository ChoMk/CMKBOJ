#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
int n;
bool Parr[1001];
bool Marr[1001];
int number;
int main()
{
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &number);
		if (number >= 0)
		{
			Parr[number] = true;
		}
		else {
			Marr[abs(number)] = true;
		}
		
	}
	for (int i = 1000; i > 0; i--) {
		if (Marr[i] == true) {
			printf("%d ", -i);
		}
	}
	for (int i = 0; i <= 1000; i++) {
		if (Parr[i] == true) {
			printf("%d ", i);
		}
	}
	printf("\n");
}