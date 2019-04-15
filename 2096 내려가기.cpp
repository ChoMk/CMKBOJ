
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
int Max[2][3];
int Min[2][3];
int caseN = 0;
int N = 0;

int main()
{
	memset(Max, -1, sizeof(Max));
	memset(Min, -1, sizeof(Min));
	scanf("%d", &caseN);

	for (int i = 0; i < caseN; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == 0)
			{
				int number = 0;
				scanf("%d", &number);
				Max[0][j] = number;
				Min[0][j] = number;
			}
			else
			{
				int number = 0;
				scanf("%d", &number);
				Max[1][j] = number;
				Min[1][j] = number;
			}
		}
		if (i != 0)
		{
			Max[1][0] = max(Max[0][0], Max[0][1]) + Max[1][0];
			Max[1][1] = max(max(Max[0][0], Max[0][1]), Max[0][2]) + Max[1][1];
			Max[1][2] = max(Max[0][1], Max[0][2]) + Max[1][2];
			Min[1][0] = min(Min[0][0], Min[0][1]) + Min[1][0];
			Min[1][1] = min(min(Min[0][0], Min[0][1]), Min[0][2]) + Min[1][1];
			Min[1][2] = min(Min[0][1], Min[0][2]) + Min[1][2];
			swap(Max[1], Max[0]);
			swap(Min[1], Min[0]);
		}
	}

	int F = max(max(Max[0][0], Max[0][1]), Max[0][2]);
	int S = min(min(Min[0][0], Min[0][1]), Min[0][2]);
	printf("%d %d\n", F, S);

}