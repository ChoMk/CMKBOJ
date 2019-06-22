#include<cstdio>
#include<algorithm>

using namespace std;

int Aarr[500001];
int Barr[500001];
int AID[1000001];
int BID[1000001];

int tree[2000001];

int n;
int startBottomIDX = 1;

int result;

void reconstructTree(int idx) {
	idx += startBottomIDX;
	tree[idx] = 1;
	while (idx > 1) {
		idx /= 2;
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
	}
}

int searchCnt(int boundLeft, int boundRight, int left, int right, int pos) {
	if (boundLeft > right || boundRight < left) {
		return 0;
	}
	if (boundLeft <= left && right <= boundRight)
		return tree[pos];
	return searchCnt(boundLeft, boundRight, left, (right + left) / 2, pos * 2) + searchCnt(boundLeft, boundRight, (right + left) / 2 + 1, right, pos * 2 + 1);

}

int main() {
	scanf("%d", &n);
	while (startBottomIDX < n)
		startBottomIDX *= 2;

	for (int i = 0; i < n; i++) {
		scanf("%d", &Aarr[i]);
		AID[Aarr[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &Barr[i]);
		BID[Barr[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		result += searchCnt(BID[Aarr[i]], n-1, 0, startBottomIDX - 1, 1);
		reconstructTree(BID[Aarr[i]]);
	}
	printf("%d\n", result);
}