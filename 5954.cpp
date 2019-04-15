#include<cstdio>
#include<algorithm>

int n;
int sum;
int arr[300];
int way[500002];
bool dp[500002];

int main()
{
	scanf("%d", &n);
	for (int i =0; i<n; i++)
	{
		scanf("%d", &arr[i]);
		sum += arr[i];
	}


	way[0] = 1;
	dp[0] = true;

	for (int i =0; i<n; i++)
	{
		int presentCoin = arr[i];
		for (int j =sum/2; j>=presentCoin; j--)
		{
			way[j] = (way[j] + way[j - presentCoin]) % 1000000;
			if (dp[j - presentCoin])
				dp[j] = true;
		}
	}
	int p = sum / 2;
	while (true)
	{
		if (dp[p] == true)
			break;
		p--;
	}
	printf("%d\n", (sum - p) - p);
	printf("%d\n", way[p]);
}