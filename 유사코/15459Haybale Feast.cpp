#include<cstdio>
#include<algorithm>

using namespace std;

int n;
long long m;
long long tree[400001];
long long arrM[100001];
long long startBottomIDX = 1;
long long a, b;
void constructTree() {
	for (int i = startBottomIDX - 1; i > 0; i--) {
		tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
	}

}
long long searchMax(int leftBound, int rightBound, int left, int right, int pos) {
	if (leftBound > right || rightBound < left)
		return 0;
	if (leftBound <= left && right <= rightBound)
		return tree[pos];
	return max(searchMax(leftBound, rightBound, left, (left + right) / 2, pos * 2),searchMax(leftBound, rightBound, (left+right)/2+1, right, pos*2+1));
}
int main() {

	scanf("%d %lld", &n, &m);
	while (startBottomIDX < n) {
		startBottomIDX *= 2;
	}
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &a, &b);
		arrM[i] = a;
		tree[startBottomIDX + i] = b;
	}
	constructTree();
	long long result = 1000000001;
	long long curM = 0;
	int tail = 0;
	int head = 0;
	while (true) {
		if (tail == n - 1)
			break;
		while (true) {
			if (curM >= m)
				break;
			if (head == n+1)
				break;

			curM += arrM[head];
			head++;
		}
		if (head == n+1)
			break;
		result = min(result, searchMax(tail, head-1, 0, startBottomIDX - 1, 1));
		curM -= arrM[tail];
		tail++;
	}
	printf("%d\n", result);

}