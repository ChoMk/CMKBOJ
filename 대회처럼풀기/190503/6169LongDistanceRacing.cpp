#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;

int n;
int t;
int u;
int f;
int d;
char temp;
vector<pair<int, int>> arr;
int result;

int main() {
	cin >> t >> n >> u >> f >> d;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp == 'u') {
			arr.push_back({ u,d });
		}
		else if (temp == 'f') {
			arr.push_back({ f,f });
		}
		else {
			arr.push_back({ d,u });
		}
	}
	int curSum = 0;
	for (int i = 0; i < n; i++) {
		curSum += (arr[i].first + arr[i].second);
		if (curSum == t) {
			printf("%d\n", i + 1);
			break;
		}
		if (curSum > t) {
			printf("%d\n", i);
			break;
		}
	}
}