#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>


using namespace std;

int n;
int arr[101][3];
int dp[10002][10002];
int dptraceA[10002][10002];
int dptraceW[10002][10002];
int dptraceV[10002][10002];
vector<int> result;

int fun(int area, int weight)
{
	int &reg = dp[area][weight];
	if (reg != -1)
		return reg;

	reg = 0;
	for (int i = 0; i<n; i++)
	{
		if ((arr[i][0] < area) && (arr[i][2] < weight))
		{
			int temp = fun(arr[i][0], arr[i][2]) + arr[i][1];
			if (temp > reg)
			{
				reg = temp;
				dptraceA[area][weight] = arr[i][0];
				dptraceW[area][weight] = arr[i][2];
				dptraceV[area][weight] = i + 1;
			}
		}
	}
	return reg;
}


int main()
{
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i<n; i++)
	{
		scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
	}

	fun(10001, 10001);

	int nextA = 10001;
	int nextW = 10001;

	while (true)
	{
		if (dptraceA[nextA][nextW] == 0)
		{
			break;
		}
		result.push_back(dptraceV[nextA][nextW]);
		int tempA = nextA;
		int tempW = nextW;
		nextA = dptraceA[tempA][tempW];
		nextW = dptraceW[tempA][tempW];




	}
	printf("%d\n", result.size());
	for (int i = result.size() - 1; i >= 0; i--)
	{
		printf("%d\n", result[i]);
	}
}