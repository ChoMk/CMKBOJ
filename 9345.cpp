#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
int t;
int n, k;
int q, a, b;
int arr[100000];
int maxTree[400000];
int minTree[400000];

int makeMaxTree(int start, int end, int pos) {
	if (start == end) {
		return maxTree[pos] = arr[start];
	}
	return maxTree[pos] = max(makeMaxTree(start, (start + end) / 2, pos * 2), makeMaxTree((start + end) / 2 + 1, end, pos * 2 + 1));
}

int makeMinTree(int start, int end, int pos) {
	if (start == end) {
		return minTree[pos] = arr[start];
	}
	return minTree[pos] = min(makeMinTree(start, (start + end) / 2, pos * 2), makeMinTree((start + end) / 2 + 1, end, pos * 2 + 1));

}

int searchMaxTree(int left, int right, int start, int end, int pos) {
	if (left > end || right < start) {
		return -1;
	}
	if (left <= start && end <= right) {
		return maxTree[pos];
	}
	return max(searchMaxTree(left, right, start, (start + end) / 2, pos * 2), searchMaxTree(left, right, (start + end) / 2 + 1, end, pos * 2 + 1));
}


int searchMinTree(int left, int right, int start, int end, int pos){
	if (left > end || right < start) {
		return 987654321;
	}
	if (left <= start && end <= right) {
		return minTree[pos];
	}
	return min(searchMinTree(left, right, start, (start + end) / 2, pos * 2), searchMinTree(left, right, (end + start) / 2 + 1, end, pos * 2 + 1));
}



void changeMaxTree(int idx, int val, int start, int end, int pos) {
	if (idx<start || idx>end) {
		return;
	}
	if (start == end) {
		maxTree[pos] = val;
		return;
	}
	changeMaxTree(idx, val, start, (start + end) / 2, pos * 2);
	changeMaxTree(idx, val, (start + end) / 2 + 1, end, pos * 2 + 1);
	maxTree[pos] = max(maxTree[pos*2], maxTree[pos*2+1]);

}
void changeMinTree(int idx, int val, int start, int end, int pos) {
	if (idx<start || idx>end) {
		return;
	}
	if (start == end) {
		minTree[pos] = val;
		return;
	}
	changeMinTree(idx, val, start, (start + end) / 2, pos * 2);
	changeMinTree(idx, val, (start + end) / 2 + 1, end, pos * 2 + 1);
	minTree[pos] = min(minTree[pos*2], minTree[pos*2+1]);
}
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &k);
		for (int i = 0; i < n; i++) {
			arr[i] = i;
		}
		makeMaxTree(0, n - 1, 1);
		makeMinTree(0, n - 1, 1);
		for (int i = 0; i < k; i++) {
			scanf("%d %d %d", &q, &a, &b);
			if (q == 0) {
				changeMaxTree(a, arr[b], 0, n - 1, 1);
				changeMinTree(a, arr[b], 0, n - 1, 1);

				changeMaxTree(b, arr[a], 0, n-1, 1);
				changeMinTree(b, arr[a], 0, n-1, 1);

				swap(arr[a], arr[b]);
			}//a,b교환
			else {
				int tempMax = searchMaxTree(a, b, 0, n - 1, 1);
				int tempMin = searchMinTree(a, b, 0, n - 1, 1);
				if (b == tempMax && a == tempMin) {
					printf("YES\n");
				}
				else {
					printf("NO\n");
				}

			}//끝자락 확인
		}

	}


}