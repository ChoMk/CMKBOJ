#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int arr[4000001];
vector<int> prime;
int n;
int result;
int main() {
	int num = 2;
	while (true) {
		if (num > 4000000)
			break;
		if (arr[num] != 0) {
			num++;
			continue;
		}
		prime.push_back(num);
		int tempNum = num;
		while (true) {
			
			if (tempNum > 4000000)
				break;
			arr[tempNum]++;
			tempNum += num;
		}
		
	}
	scanf("%d", &n);
	int left = 0;
	int right = 0;
	int sum = prime[0];
	while (1) {
		if (right == prime.size()-1)break;
		if (sum == n) {
			result++;
			sum += prime[++right];
		}
		else if (sum < n)sum += prime[++right];
		else if (sum > n)sum -= prime[left++];
	}
	printf("%d\n", result);
}