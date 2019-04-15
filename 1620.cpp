#include<cstdio>
#include<map>
#include<string>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int n, m;
string temp;
string save[100100];
map<string, int>dic;
char tempc[30];


int main()
{
	scanf("%d %d", &n, &m);
	cin.ignore(1);
	for (int i = 0; i < n; i++)
	{
		int count = 0;
		while (true)
		{

			scanf("%c", &tempc[count]);
			if (tempc[count] == '\n')
			{
				
				break;
			}
			else
			{
				temp += tempc[count];
			}
			count++;
		}


		save[i] = temp;

		dic[temp] = i + 1;
		temp.clear();
		
	}
	for (int i = 0; i < m; i++)
	{
		int count = 0;
		while (true)
		{

			scanf("%c", &tempc[count]);
			if (tempc[count] == '\n')
			{
				break;
			}
			else
			{
				temp += tempc[count];
			}
			count++;
		}
		if (temp[0]<'A')
		{
			cout << save[stoi(temp) - 1];
			printf("\n");
		}
		else
		{
			printf("%d\n", dic[temp]);//map에서 찾을때 첫번째 인자가 킷값이다.

		}
		temp.clear();
	}

}