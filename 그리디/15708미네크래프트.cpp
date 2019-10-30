#include<algorithm>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

int n, t, p;
priority_queue<int> pq;
int arr[100001];
int currentSum, result, currentSize;

int main() {
	scanf("%d %d %d", &n, &t, &p);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++) {
		if (t <= p * i)
			break;
		currentSize++;
		currentSum += arr[i];
		pq.push(arr[i]);
		while (!pq.empty() && currentSum > t) {
			currentSum -= pq.top();
			currentSize--;
			pq.pop();
		}
		if (currentSum > t)
			break;
		result = max(result, currentSize);
		currentSum += p;
	}
	printf("%d\n", result);
}