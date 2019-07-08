#include<cstdio>
#include<algorithm>

using namespace std;
int n;
int bottomStart = 1;

long long a, b;
long long result = 0;

pair<long long, long long> arrX[50001];
pair<long long, long long> arrY[50001];
long long treeMinx[200001];
long long treeMaxx[200001];
long long treeMiny[200001];
long long treeMaxy[200001];

void constructMinX() {
	for (int i = bottomStart - 1; i > 0; i--) {
		treeMinx[i] = min(treeMinx[i * 2], treeMinx[i * 2 + 1]);
	}
}
long long searchMinX(int leftBound, int rightBound, int left, int right, int pos) {
	if (leftBound > right || rightBound < left) {
		return 1000000001;
	}
	if (leftBound <= left && right <= rightBound)
		return treeMinx[pos];
	return min(searchMinX(leftBound, rightBound, left, (left + right) / 2, pos * 2), searchMinX(leftBound, rightBound, (left + right) / 2 + 1, right, pos * 2 + 1));
}
void constructMaxX() {
	for (int i = bottomStart - 1; i > 0; i--) {
		treeMaxx[i] = max(treeMaxx[i * 2], treeMaxx[i * 2 + 1]);
	}

}
long long searchMaxX(int leftBound, int rightBound, int left, int right, int pos) {
	if (leftBound > right || rightBound < left) {
		return 0;
	}
	if (leftBound <= left && right <= rightBound)
		return treeMaxx[pos];
	return max(searchMaxX(leftBound, rightBound, left, (left + right) / 2, pos * 2), searchMaxX(leftBound, rightBound, (left + right) / 2 + 1, right, pos * 2 + 1));
}
void constructMinY() {
	for (int i = bottomStart - 1; i > 0; i--) {
		treeMiny[i] = min(treeMiny[i * 2], treeMiny[i * 2 + 1]);
	}
}
long long searchMinY(int leftBound, int rightBound, int left, int right, int pos) {
	if (leftBound > right || rightBound < left) {
		return 1000000001;
	}
	if (leftBound <= left && right <= rightBound)
		return treeMiny[pos];
	return min(searchMinY(leftBound, rightBound, left, (left + right) / 2, pos * 2), searchMinY(leftBound, rightBound, (left + right) / 2 + 1, right, pos * 2 + 1));
}
void constructMaxY() {
	for (int i = bottomStart - 1; i > 0; i--) {
		treeMaxy[i] = max(treeMaxy[i * 2], treeMaxy[i * 2 + 1]);
	}
}
long long searchMaxnY(int leftBound, int rightBound, int left, int right, int pos) {
	if (leftBound > right || rightBound < left) {
		return 0;
	}
	if (leftBound <= left && right <= rightBound)
		return treeMaxy[pos];
	return max(searchMaxnY(leftBound, rightBound, left, (left + right) / 2, pos * 2), searchMaxnY(leftBound, rightBound, (left + right) / 2 + 1, right, pos * 2 + 1));

}


int main() {
	scanf("%d", &n);
	while (bottomStart < n) {
		bottomStart *= 2;
	}
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &a, &b);
		arrX[i] = { a,b };
		arrY[i] = { b,a };
	}
	sort(arrX, arrX + n);
	sort(arrY, arrY + n);

	for (int i = 0; i < n; i++) {
		treeMinx[bottomStart + i] = arrX[i].second;
		treeMaxx[bottomStart + i] = arrX[i].second;
		treeMiny[bottomStart + i] = arrY[i].second;
		treeMaxy[bottomStart + i] = arrY[i].second;
	}

	for (int i = n; i < bottomStart; i++) {
		treeMinx[bottomStart + i] = 1000000001;
		treeMiny[bottomStart + i] = 1000000001;

	}
	constructMinX();
	constructMaxX();
	constructMinY();
	constructMaxY();
	long long recOne = (arrX[n - 1].first - arrX[0].first)*(searchMaxX(0, n - 1, 0, bottomStart - 1, 1) - searchMinX(0, n - 1, 0, bottomStart - 1, 1));
	long long result = 0;
	for (int i = 0; i < n - 1; i++) {
		result = max(result, recOne - ((arrX[i].first - arrX[0].first)*(searchMaxX(0, i, 0, bottomStart - 1, 1) - searchMinX(0, i, 0, bottomStart - 1, 1)) +
			(arrX[n - 1].first - arrX[i + 1].first)*(searchMaxX(i + 1, n - 1, 0, bottomStart - 1, 1) - searchMinX(i + 1, n - 1, 0, bottomStart - 1, 1))));
	}
	for (int i = 0; i < n - 1; i++) {

		result = max(result, recOne - ((arrY[i].first - arrY[0].first)*(searchMaxnY(0, i, 0, bottomStart - 1, 1) - searchMinY(0, i, 0, bottomStart - 1, 1)) +
			(arrY[n-1].first - arrY[i+1].first)*(searchMaxnY(i + 1, n - 1, 0, bottomStart - 1, 1) - searchMinY(i + 1, n - 1, 0, bottomStart - 1, 1))));
	}
	printf("%lld\n", result);
}