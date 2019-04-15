#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
#include<math.h>
using namespace std;

int w, h, l1, l2;
int result;
int main()
{
	scanf("%d %d %d %d", &w, &h, &l1, &l2);
	if (l1 > l2)
	{
		int t = l1;
		l1 = l2;
		l2 = t;
	}
	w++;
	h++;
	for (int i =0; i<h; i++)
	{
		for (int j =0; j<w/2; j++)
		{
			for (int k = i+1; k<h; k++)
			{
				for (int l = 0; l<w; l++)
				{
					if (l == j)
						continue;
					double temp = sqrt(double((i - k)*(i - k) + (j - l)*(j - l)));
					if (temp < l1)
						continue;
					if (temp > l2)
						continue;
					result++;
				}
			}
		}
	}
	result *= 2;
	if (w % 2 == 1)
	{
		for (int i = 0; i<h; i++)
		{
			for (int j = w/2; j<=w / 2; j++)
			{
				for (int k = i + 1; k<h; k++)
				{
					for (int l = 0; l<w; l++)
					{
						if (l == j)
							continue;
						double temp = sqrt(double((i - k)*(i - k) + (j - l)*(j - l)));
						if (temp < l1)
							continue;
						if (temp > l2)
							continue;
						result++;
					}
				}
			}
		}
	}
	printf("%d\n", result);
}