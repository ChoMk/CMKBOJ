#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector<int> saveNode[100001];
int n;
int a, b;
int visit[100001];
int qVisit[100001];
vector<int> result;
queue<int> q;
bool startNode[100001];

int main()
{
	scanf("%d", &n);
	for (int i =0; i<n-1; i++)
	{
		scanf("%d %d", &a, &b);
		saveNode[a].push_back(b);
		visit[b] ++;
	}
	for (int i =1; i<=n; i++)
	{
		if (visit[i] == 0)
		{
			q.push(i);
			qVisit[i] = 1;
			startNode[i] = true;
		}
	}
	while (true)
	{
		if (q.size() == 0)
			break;
		if (q.size() == 1)
			result.push_back(q.front());
		int presentNode = q.front();
		q.pop();
		if (saveNode[presentNode].size() == 0)
		{
			break;
		}
		if (visit[presentNode] != 0)
		{
			q.push(presentNode);
		}
		else
		{
			for (int i =0; i<saveNode[presentNode].size(); i++)
			{
				if (qVisit[saveNode[presentNode][i]] == 0)
				{
					qVisit[saveNode[presentNode][i]] = 1;
					visit[saveNode[presentNode][i]] --;
					q.push(saveNode[presentNode][i]);
				}
				else
				{
					visit[saveNode[presentNode][i]] --;
				}



			}
		}


	}

	for (int i =0; i<result.size(); i++)
	{
		if (startNode[result[i]] ==false )
		{
			printf("%d\n", result[i]);
		}
	}


}