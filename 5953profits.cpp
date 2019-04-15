#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

int n;
int arr[100011];
int result = -987654321;


int main()
{
	scanf("%d", &n);
	for (int i =0; i<n; i++)
	{
		scanf("%d", &arr[i]);
		
	}
	int sum = 0;
	for (int i =0; i<n; i++)
	{
		sum += arr[i];
		if (sum > result) {
			result = sum;
		}
		if (sum < 0) {
			sum = 0;
		}
	}
	printf("%d\n", result);
}