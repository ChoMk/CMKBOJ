#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	int t, n;
	scanf("%d", &t);
	while (t--)
	{
		map<string, int> m;
		scanf("%d", &n);
		while (n--)
		{
			string a, b;
			cin >> a >> b;
			m[b]++;
		}
		int ans = 1;
		for (auto it = m.begin(); it != m.end(); it++)
			ans *= it->second + 1;
		printf("%d\n", ans - 1);
	}
	return 0;
}
