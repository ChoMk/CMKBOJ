#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

int arr[100001];
int n;
int m;
int a;
int heapSize;

int promote(int curNode, int hStop, int h) {
	if (h <= hStop) {
		return curNode;
	}
	else if (curNode * 2 + 1 <= heapSize) {
		if (arr[curNode * 2] < arr[curNode * 2 + 1]) {
			swap(arr[curNode], arr[curNode * 2 + 1]);
			return promote(curNode * 2 + 1, hStop, h - 1);
		}
		else {
			swap(arr[curNode], arr[curNode * 2]);
			return promote(curNode * 2, hStop, h - 1);
		}
	}
	else if(curNode*2<=heapSize){
		if (arr[curNode] < arr[curNode * 2]) {
			swap(arr[curNode], arr[curNode * 2]);
			return curNode * 2;
		}
	}
}

void bubbleUpHeap(int curNode) {
	if (curNode == 1)
		return;
	if (arr[curNode / 2] < arr[curNode]) {
		swap(arr[curNode / 2], arr[curNode]);
		bubbleUpHeap(curNode / 2);
	}
	return;
}

void fixFastHeap(int curNode, int h) {
	if (h <= 1) {
		if (h == 0)
			return;
		else {
			if (curNode * 2 > heapSize)
				return;
			if (curNode * 2 + 1 <= heapSize) {
				int maxVal = max(max(arr[curNode * 2], arr[curNode * 2 + 1]), arr[curNode]);
				if (maxVal == arr[curNode]) {
					return;
				}
				else if (maxVal == arr[curNode*2]) {
					swap(arr[curNode], arr[curNode * 2]);
					
				}
				else {
					swap(arr[curNode], arr[curNode * 2 + 1]);
					
				}
			}
			else {
				if (arr[curNode] < arr[curNode * 2]) {
					swap(arr[curNode], arr[curNode * 2]);
				}
			}
			
			
			return;
		}
	}
	else {
		int hstop = h / 2;
		int hstopNode = promote(curNode, hstop, h);
		if (arr[hstopNode / 2] < arr[hstopNode]) {
			bubbleUpHeap(hstopNode);
		}
		else {
			fixFastHeap(hstopNode, hstop);
		}
	}
}


void fixHeap(int curNode) {
	if (curNode * 2 > heapSize)
		return;
	if (curNode * 2 + 1 > heapSize) {
		if (arr[curNode] < arr[curNode * 2]) {
			swap(arr[curNode], arr[curNode * 2]);
		}
		return;
	}
	int curVal = arr[curNode];
	int leftVal = arr[curNode * 2];
	int rightVal = arr[curNode * 2 + 1];
	int maxVal = max(curVal, max(leftVal, rightVal));
	if (maxVal == curVal) {
		return;
	}
	else if (maxVal == leftVal) {
		swap(arr[curNode], arr[curNode * 2]);
		fixHeap(curNode * 2);
	}
	else {
		swap(arr[curNode], arr[curNode * 2+1]);
		fixHeap(curNode * 2+1);
	}
	return;
}


void constructHeap(int curNode) {
	if (curNode > heapSize)
		return;
	constructHeap(curNode * 2);
	constructHeap(curNode * 2 + 1);
	fixHeap(curNode);
	return;
}

void heapSort() {
	int h; // 높이 계산
	for (int i = 0; i < n - 1; i++) {
		swap(arr[1], arr[heapSize]);
		heapSize--;
		h = log2(heapSize);
		//fixHeap(1);
		fixFastHeap(1, h);
	}
}

int bs(int left, int right, int val) {
	if (left > right)
		return 0;
	int mid = (left + right) / 2;
	if (arr[mid] == val)
		return 1;
	else if(arr[mid]<val)
	{
		return bs(mid + 1, right, val);
	}
	else {
		return bs(left, mid-1, val);
	}

}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i+1]);
	}
	heapSize = n;
	constructHeap(1);
	heapSort();
	//sort(arr, arr + n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &a);
		printf("%d\n", bs(1, n, a));
	}
}
