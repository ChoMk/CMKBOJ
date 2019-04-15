#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;


int f, s, t;


int main()
{
	scanf("%d %d %d", &f, &s, &t);
	if (f == s && s == t) {
		printf("%d\n", 10000 + f * 1000);

	}
	else if (f == s)
	{
		printf("%d\n", 1000 + f * 100);
	}
	else if (s == t)
	{
		printf("%d\n", 1000 + s * 100);
	}
	else if (t == f)
	{
		printf("%d\n", 1000 + f * 100);
	}
	else {
		int temp = max(s, max(t, f)) * 100;
		printf("%d\n", temp);
	}



}