#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int n;
int arr[101][101];
int visit[101];
vector<int> result;

bool fun(int idx)
{
	visit[idx] = 1;
	int cnt = 0;
	for (int i =0; i<n; i++)
	{
		if (i == idx) {
			continue;
		}
		else if (arr[idx][i] == 0)
		{
			cnt++;
			for (int j=0;j<n; j++)
			{
				if (arr[idx][j] != arr[i][j])
				{

					return false;
				}
			}
			visit[i] = 1;
		}
			
	}
	if (cnt == 0)
		return false;
	return true;
}


int main()
{
	scanf("%d", &n);
	for (int i =0; i<n; i++)
	{
		for (int j =0; j<n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i =0; i<n; i++)
	{
		if (visit[i] == 0)
		{
			if (fun(i))
			{
				result.push_back(i);
			}
			else {
				printf("0\n");
				return 0;
			}
		}
	}
	printf("%d\n", result.size());
	for (int i =0; i<result.size(); i++)
	{
		for (int j =0; j<n; j++)
		{
			if (arr[result[i]][j] == 0)
			{
				printf("%d ", j + 1);
			}
		}
		printf("\n");
	}
}