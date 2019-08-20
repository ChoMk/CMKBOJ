#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int sum;
vector<pair<int, int>> arr;
int a;
int main() {
	for (int i = 0; i < 3; i++) {
		scanf("%d", &a);
		sum += a;
		arr.push_back({ a, i });
	}
	sort(arr.begin(), arr.end());
	if (sum >= 100) {
		printf("OK\n");
	}
	else if (arr[0].second == 0) {
		printf("Soongsil\n");
	}
	else if(arr[0].second == 1){
		printf("Korea\n");
	}
	else {
		printf("Hanyang\n");
	}
}