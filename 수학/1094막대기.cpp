#include<cstdio>
#include<algorithm>
#include<vector>


using namespace std;
int x;
vector<int> result;
int main() {
	scanf("%d", &x);
	if (x == 64) {
		printf("1\n");
		return 0;
	}
	result.push_back(64);
	while (true) {
		sort(result.begin(), result.end());
		result[0] = result[0] / 2;
		result.push_back(result[0]);
		int tempSum = 0;
		for (int i = 0; i < result.size()-1; i++) {
			tempSum += result[i];
		}
		if (tempSum >= x) {
			result.pop_back();
		}
		if (tempSum == x)
			break;
	}
	
	printf("%d\n", result.size());
}