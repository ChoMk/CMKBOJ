#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> result;
int G;

int main() {
	scanf("%d", &G);
	
	int left = 1;
	int right = 1;
	while (1) {
		if (right-left == 1 && right*right - left * left >G)break;
		if (right*right - left * left == G) {
			result.push_back(right);
			++right;
		}
		else if (right*right - left * left < G)right++;
		else if (right*right - left * left > G)left++;
	}
	if (result.size() == 0) {
		printf("-1\n");
		return 0;
	}
	for (int i = 0; i < result.size(); i++) {
		int num = result[i];
		printf("%d\n", num);
	}

}