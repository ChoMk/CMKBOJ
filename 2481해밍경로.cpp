#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int n, m, k;
string bin[100001];
int destination[51];
vector<int> node[100001];
int cntOne[100001];
int dp[100001];
int dptrace[100001];
int visit[100001];



int fun(int present, int lay)
{
	
	if (visit[present] < lay)
		return 987654321;
	visit[present] = lay;
	if (dp[present] != 987654321)
		return dp[present];
	if (present == 0)
		return 1;
	
	for (int i =0; i<node[present].size(); i++)
	{
		int next = node[present][i];
		int temp = fun(next, lay + 1)+1;
		if (dp[present] > temp) {
			dp[present] = temp;
			dptrace[present] = next;
		}
	}
	return dp[present];
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i =0; i<n; i++)
	{
		cin >> bin[i];
		int cnt = 0;
		for (int j =0; j<k; j++)
		{
			if (bin[i][j] == '1')
				cnt++;
		}
		cntOne[i] = cnt;
	}
	scanf("%d", &m);
	for (int i =0; i<m; i++)
	{
		scanf("%d", &destination[i]);
		destination[i]--;
	}
	for (int i =0; i<n; i++)
	{
		for (int j =i+1; j<n; j++)
		{
			if (abs(cntOne[i] - cntOne[j]) != 1)
				continue;
			int cnt = 0;
			for (int x = 0; x<k; x++)
			{

				if (bin[i][x] != bin[j][x])
					cnt++;




			}
			if (cnt == 1)
			{
				node[i].push_back(j);
				node[j].push_back(i);
			}
		}
	}
	for (int i = 0; i < n; i++) {

		dp[i] = 987654321;
	}
	for (int i =0; i<m; i++)
	{
		for (int i = 0; i < n; i++) {

			visit[i] = 987654321;
		}
		int temp = fun(destination[i], 0);
		
		if (temp >= 987654321) {
			printf("-1\n");
		}
		else
		{
			vector<int> result;
			int state = destination[i];
			result.push_back(state + 1);
			
			while (true)
			{

				result.push_back(dptrace[state] + 1);
				state = dptrace[state];
				if (state == 0)
					break;
			}
			reverse(result.begin(), result.end());
			for (int j = 0; j < result.size(); j++)
			{
				printf("%d ", result[j]);
			}
			printf("\n");
		}
	}


}